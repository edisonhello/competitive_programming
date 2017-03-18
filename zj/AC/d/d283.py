import sys
f=[0,1]
for i in range(2,22222):
  f.append(f[-1]+f[-2])
for i in sys.stdin:
  print(f[int(i)])
