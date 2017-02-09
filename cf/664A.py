def gcd(a,b):
    while a!=0 and b!=0:
        if a>b:
            a=a-int(a/b)*b
        else:
            b=b-int(b/a)*a
    if a==0:
        print b
    else:
        print a


string=raw_input()
a,b=string.split()

gcd(int(a),int(b))
