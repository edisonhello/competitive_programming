#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int ct[2000005];

int main(){
    int n,i,t,p,pos;
    while(~scanf("%d",&n)){
        int mx=0;
        memset(ct,0xff,sizeof(ct));
        ct[1000000]=0;
        for(i=1,p=0;i<=n;++i){
            scanf("%d",&t);
            if(t&(1<<31))t=-1;
            else if(t)t=1;
            p+=t;
            pos=p+1000000;
            if(~ct[pos])mx=max(mx,i-ct[pos]);
            else ct[pos]=i;
        }
        printf("%d\n",mx);
    }
}
