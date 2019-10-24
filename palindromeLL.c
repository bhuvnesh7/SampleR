#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char c;
  struct Node* prev;
  struct Node* next;
};

void insert_front(struct Node ** front, struct Node ** rear , char ch)
{
  struct Node * newnode;
  newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->c = ch;
  newnode->prev = NULL;
  newnode->next = NULL;
  if(*front==NULL)
  {
    *front = newnode;
    *rear = newnode;
  }
  else
  {
    newnode->next = *front;
    (*front)->prev = newnode;
    
    *front = newnode;
  }
}

void insert_rear(struct Node ** front, struct Node ** rear , char ch)
{
  struct Node * newnode;
  newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->c = ch;
  newnode->prev = NULL;
  newnode->next = NULL;
  if(*front==NULL || *rear==NULL)
  {
    *front = newnode;
    *rear = newnode;
  }
  else
  {
    (*rear)->next = newnode;
    newnode->prev = *rear;
    *rear = newnode;
  }
}

char del_front(struct Node** front, struct Node** rear)
{
  char popped='\0';
  if(*front!=NULL)
  { struct Node* temp = *front;
   popped = temp->c;
   *front = (*front)->next;
   free(temp);
   
  }  
  if(*front!=NULL)
  {(*front)->prev=NULL;}
  else
  {
    *front = *rear = NULL;
  }
  return popped;
}

char del_rear(struct Node** front, struct Node** rear)
{
  char popped = '\0';
  if(*rear!=NULL)
  {
    struct Node* temp = *rear;
    popped = temp->c;
    *rear = (*rear)->prev;
    free(temp);
    
  }  
  if(*rear!=NULL)
  {(*rear)->next = NULL;}
  else
  {
    *front = *rear = NULL;
  }
  return popped;
}

void display(struct Node** front)
{
  struct Node* p = *front;
  printf("\n");
  while(p!=NULL)
  {
    printf("%c",p->c);
    p = p->next;
  }
  printf("\n");
}

int palindrome(struct Node** front, struct Node** rear)
{
  int flag=0;
  
  while(*front!=*rear)
  {
    char a = del_front(front,rear);
    char b = del_rear(front,rear);
    if(a!=b)
    {
      flag=1;
      break;
    }
  }

  return flag;
}





int main(void) {
  struct Node* front = NULL;
  struct Node* rear = NULL;
  char s[20],a,b;
  int i,j,k;
  printf("Enter a string : \n");
  scanf("%s",s);
  //insert_rear(&front,&rear,'a');
  
  for(i=0;s[i]!='\0';i++)
  {
    insert_rear(&front,&rear,s[i]);
  }

  
  display(&front);

  int ans = palindrome(&front,&rear);
  if(ans==0)
  {
    printf("It is a palindrome");
  }

  else if(ans==1)
  {
    printf("It is NOT a palindrome");
  }

  






  return 0;
}