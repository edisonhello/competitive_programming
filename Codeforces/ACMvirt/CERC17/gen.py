n = int(input())

with open("j.in", "w") as f:
    f.write("{}\n".format(n))
    for i in range(1, n):
        f.write("{} {}\n".format(i, i + 1))
