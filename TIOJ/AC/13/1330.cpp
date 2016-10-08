#include<stdio.h>
short t,ts,v;
char c;
inline int rit(){
    t=0;
    do{
        c=getchar_unlocked();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0'&&c<='9');
    return t;
}
int main(){
    ts=rit();
    do{
        v=rit();
        putchar_unlocked((v&1)+'0');
        putchar_unlocked('\n');
    }while(--ts);
}
