#include <stdio.h>
#include <stdlib.h>

#define limit 100000000
#define size 1000000

int main(void) {
  unsigned long long int i,j,k,c;
  int *sieve;
  sieve = malloc(sizeof(int)*limit);
  int *primes;
  primes = malloc(sizeof(int)*size);

  sieve[0] = sieve[1] = -1;

  for(i=2;i<limit;i++)
  {
    sieve[i] = 0;
  }

  for(i=2;i<limit;i++)
  {
    if(sieve[i]==0)
    {
      for(j=i;i*j<limit;j++)
      {
        sieve[i*j] = 1;
      }
    }
  }

  primes[0] = 2; primes[1]= 3;
  c=2;

  for(i=1;6*i<limit;i++)
  {
    if(sieve[6*i-1]==0)
    {
      primes[c] = 6*i-1;
      c++;
    }

    if(sieve[6*i+1]==0)
    {
      primes[c] = 6*i+1;
      c++;
    }
  }

 
 /*
  for(i=4;i<limit;i++)
  {
    if(sieve[i]==0)
    {
      primes[c] = i;
      c++;
    }  
  } 
  */

  printf("Prime Numbers : \n");
  for(i=0;i<100000;i++)
  {
    printf("%lluth Prime Number : %d\n",i+1,primes[i]);
  }


  

  return 0;
}