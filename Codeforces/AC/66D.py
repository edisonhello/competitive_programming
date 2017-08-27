isprime = [1 for i in range(2000)]

isprime[0] = 0
isprime[1] = 0
for i in range(2,2000,1):
    if(isprime[i]):
        j = i*i
        while j < 2000:
            isprime[j] = 0
            j += i

prime = []
for i in range(2,2000,1):
    if(isprime[i]):
        prime.append(i)

n = int(input())
if(n==2):
    print('-1')
    exit(0)

for i in range(n):
    val = 1
    for j in range(n):
        if i==j : continue
        val *= prime[j]
    print(val)
