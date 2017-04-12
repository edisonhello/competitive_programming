import sys
from decimal import *

getcontext().prec = 11111
for i in sys.stdin:
    a,b,n = map(int,i.split())
    print(format(Decimal(a)/Decimal(b),'.'+str(n+1000)+'f')[:-1000])
