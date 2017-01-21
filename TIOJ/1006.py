import subprocess
import random as r
args = "./1006b"
argss= "./1006_a"
while 1:
    p = subprocess.Popen(args, stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    pp= subprocess.Popen(argss,stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    a=r.randint(0,999999)
    # a=
    b=r.randint(1,999)
    p.stdin.write(str(a)+'\n'+str(b)+'\n');
    pp.stdin.write(str(a)+'\n'+str(b)+'\n');
    # p.stdin.write('999088056764865\n980406\n');
    res = int(p.communicate()[0])
    ans = int(pp.communicate()[0])
    # print(int(p.communicate()[0]))
    print('a='+str(a)+',b='+str(b)+',ans='+str(ans)+',op='+str(res)),
    if res != ans:
        print(" WA")
        break
    else:
        print(" OK")
