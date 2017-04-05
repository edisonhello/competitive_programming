a,b=map(int,raw_input().split())
c,d=map(int,raw_input().split())
x=set()
t=0
while b+t*a < 10**4+1:
    x.add(b+t*a)
    t+=1
t=0
while d+t*c<10**4+1:
    if d+t*c in x:
        print((d+t*c)%(a*c))
        break
    t+=1
else:
    print(-1)
