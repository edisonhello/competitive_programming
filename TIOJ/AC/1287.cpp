#include<algorithm>
#include<stdio.h>

int n,a[1000006],i,t,k;
char c;
inline int rit(){
    t=0,k=1;
    do{
        c=getchar_unlocked();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0'&&c<='9');
    return t*k;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;++i){
            a[i]=rit();
        }
        std::sort(a,a+n);
        for(i=0;i<n;++i){
            if(i)putchar_unlocked(' ');
            printf("%d",a[i]);
        }
        putchar_unlocked('\n');
    }
}
