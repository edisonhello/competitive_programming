import sys

a,n = [],0

for i in sys.stdin:
    if n==0:
        n = int(i)
    else:
        a.append(int(i))
        if len(a) == n:
            a.sort()
            for ele in a:
                print(ele)
            a.clear()
            n = 0
