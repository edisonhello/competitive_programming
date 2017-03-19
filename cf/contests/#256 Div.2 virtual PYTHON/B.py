import sys

a = raw_input()
b = raw_input()

countA = {}
for c in a:
    if ord(c) in countA:
        countA[ord(c)] += 1
    else:
        countA[ord(c)] = 1
countB = {}
for c in b:
    if ord(c) in countB:
        countB[ord(c)] += 1
    else:
        countB[ord(c)] = 1

needAutomation = 0
for i in range(97,123):
    if i in countA and not i in countB:
        needAutomation = 1
    elif i in countB and not i in countA:
        print "need tree"
        sys.exit(0)
    elif i in countA and i in countB:
        if countA[i] < countB[i]:
            print "need tree"
            sys.exit(0)
        elif countA[i] > countB[i]:
            needAutomation = 1

dp = []
for i in range(105):
    tmp = []
    for j in range(105):
        tmp.append(0)
    dp.append(tmp)

aptr = 0
bptr = 0
needArray = 0
while 1:
    if aptr >= len(a) and bptr < len(b):
        needArray = 1
        break
    elif aptr >= len(a) or bptr >= len(b):
        break
    elif a[aptr] != b[bptr]:
        aptr += 1
    else:
        aptr += 1
        bptr += 1

if needArray and needAutomation:
    print "both"
elif needArray:
    print "array"
else:
    print "automaton"
