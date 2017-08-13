#include<stdio.h>
const long long mod=1e9+9;

long long ans[111];
void pre(){
    ans[0]=ans[1]=1;
    for(int i=2,j;i<=100;++i){
        ans[i]=ans[i-1]*3;
        for(j=1;i-j>=2;++j){
            ans[i]+=ans[i-j-1]*2;
        }
        ++ans[i];
        ans[i]=ans[i]%mod;
    }
}
int main(){
    pre();
    int ts,n; scanf("%d",&ts); while(ts--){
        scanf("%d",&n); printf("%lld\n",ans[n]);
    }
}
