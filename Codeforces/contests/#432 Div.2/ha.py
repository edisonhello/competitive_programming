n,k,t = map(int,raw_input().split())
if t<=k:
    print t
elif k<t<=n:
    print k
else:
    print n-t+k
