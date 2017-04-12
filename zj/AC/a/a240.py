import sys
from decimal import *

getcontext().prec = 191111
num = str(Decimal(1)/Decimal(17))[2:]
# print(num)

m = int(sys.stdin.readline())
for _ in range(m):
    n = int(sys.stdin.readline())
    tot = 0
    for ii in range(n):
        tot += int(num[ii])
    print(num[n-1],tot)

