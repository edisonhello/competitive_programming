n=int(input())
a=0
b=0
c=0
for i in range(n):
  x=int(input())
  if x%3==0:
    a=a+1
  if x%3==1:
    b=b+1
  if x%3==2:
    c=c+1
print(a,b,c)
