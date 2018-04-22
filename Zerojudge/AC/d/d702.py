import sys
from decimal import *

f = []
f.append(0)
f.append(0)
f.append(1)
f.append(1)
for i in range(4,1111):
    f.append(f[i-2] + f[i-3])

for i in sys.stdin:
    if i[0] == '\n':
        continue
    n = int(i)
    n += 1
    print(f[n])

