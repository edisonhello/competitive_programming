#include<cstdio>
#define ll long long
using namespace std;
int main(){
    ll n,ans=0,i;
    scanf("%lld",&n);
    bool flag=0;
    for(i=1;i*i<=n;++i){
        ans+=((n-i)/i+(i-1)*(n/i-n/(i+1)));
        if((n-i)/i==(i-1))ans-=(n-i)/i;
    }
    printf("%lld\n",ans);
}
