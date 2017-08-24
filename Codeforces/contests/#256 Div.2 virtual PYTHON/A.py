from math import floor

a = map(int,raw_input().split())
b = map(int,raw_input().split())
n = int(raw_input())

tota = 0
for i in a:
    tota += i
totb = 0
for i in b:
    totb += i


need = 0
need += int(floor(tota/5))
if tota%5 != 0:
    need += 1
need += int(floor(totb/10))
# print tota,totb,need
if totb%10 != 0:
    need += 1

if need <= n:
    print "YES"
else:
    print "NO"
