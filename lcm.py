
def gcd(a,b):
  if b==0:
    return a
  else:
    a1=a%b
    return gcd(b,a1)
x,y=map(int, input().split())
z=x*y
l=z/gcd(x,y)
print(l)

