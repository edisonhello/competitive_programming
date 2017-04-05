import sys
ts = int(sys.stdin.readline())
for _ in range(ts):
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().split()
    s = s[1:]
    for i in s:
        if n%int(i)!=0:
            print("{} - Simple.".format(n))
            break
        if i==s[-1]:
            print("{} - Wonderful.".format(n))
