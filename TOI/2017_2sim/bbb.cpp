#include<stdio.h>
#include<cstring>
using namespace std;

int seg[100009],n,m;
bool dd[100009];

inline int rit();

void kill(int k){
    memset(dd,0,sizeof(dd)); dd[0]=1;
    int ptr=0,leftpp=n; bool flag=0;
    if(n==k)--k,flag=1;
    for(int i=1;i<=k;++i){
        int step=(seg[i]-1)%leftpp+1;
//        if(step>leftpp)
        while(dd[ptr]){++ptr; if(ptr>n)ptr-=n;}
        for(int j=1;j<step;++j){
            ++ptr; if(ptr>n)ptr-=n;
            while(dd[ptr]){++ptr; if(ptr>n)ptr-=n;}
        }
        dd[ptr]=1; --leftpp;
    }
    if(!flag)printf("%d\n",ptr);
    else{
        while(dd[ptr]){++ptr; if(ptr>n)ptr-=n;}
        printf("%d\n",ptr);
    }
}

int main(){
    n=rit(),m=rit();
    for(int i=1;i<n;++i)seg[i]=rit();
    int a,b,c;
    while(m--){
        c=rit();
        if(c==1){
            a=rit(),b=rit();
            seg[a]=b;
        }
        else{
            a=rit();
            kill(a);
        }
    }
}

inline int rit(){
    int x=0; char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        x=x*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return x;
}
