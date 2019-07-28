#!/usr/bin/python3
t = int(input())

for i in range(t):
    [a, b] = map(int, input().strip().split(' '))
    print(a * b)
