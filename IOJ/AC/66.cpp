#include<cstdio>
#include<bitset>
using namespace std;
#define putchar putchar_unlocked

bitset<(1<<17)> u;
int main(){
    int k; scanf("%d",&k);
    int n=(1<<k); printf("%d\n",n);
    int now=0,cnt=k-1;
    for(int i=1,x=(1<<k)-1;i<k;++i)putchar('0'),x=(x<<1)&((1<<k)-1),u[x]=1;
    while(cnt<n){
        now<<=1;
        now&=(1<<k)-1;
        if(u[now])now|=1;
        u[now]=1;
        putchar((now&1?'1':'0'));
        ++cnt;
    }
}
