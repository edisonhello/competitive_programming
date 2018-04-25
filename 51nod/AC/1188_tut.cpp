#pragma GCC optimize("Ofast")
#include<cstdio>
#include<bitset>
using namespace std;

bitset<5000005> nprime;
int prime[1000005],psize;
int phi[5000005];
long long ans[5000005];

int main(){
    for(int i=2;i<=5000000;++i){
        if(!nprime[i]){
            phi[i]=i-1;
            prime[psize]=i;
            ++psize;
        }
        for(int j=0;;++j){
            if(i*prime[j]>5000000)break;
            nprime[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    for(int i=1;i<=5000000;++i){
        for(int j=2;i*j<=5000000;++j)ans[i*j]+=1ll*i*phi[j];
        ans[i]+=ans[i-1];
    }
    int t,n; scanf("%d",&t); do{
        scanf("%d",&n); printf("%lld\n",ans[n]);
    }while(--t);
}
