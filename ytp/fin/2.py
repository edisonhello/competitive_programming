import math
x = list(map(float,raw_input().split(',')))
dist = 0.0
dist += x[0]*x[1]*x[1]/2
spd = x[0]*x[1]
dist += spd*x[2]
spd2 = spd - x[3]*x[4]
dist += (spd+spd2)*x[4]/2
print(round(dist,1))
