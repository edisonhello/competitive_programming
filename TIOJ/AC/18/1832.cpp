#include<cstdio>
#define ll long long
ll h[1000005];
using namespace std;
int main(){
    int n,q,l,r;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%lld",h+i);
        h[i]^=h[i-1];
    }
    while(q--){
        scanf("%d%d",&l,&r);
        printf("%lld\n",h[r]^h[l-1]);
    }
}
