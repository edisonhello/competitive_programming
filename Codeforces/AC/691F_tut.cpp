#include<bits/stdc++.h>
using namespace std;

int a[1000006],cnt[3000006],pre[3000006];
long long ans[3000006];
vector<pair<int,int>> num;

int main(){
    srand(time(0));
    int n; scanf("%d",&n);
    // int n=10000;
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),++cnt[a[i]];
    // for(int i=1;i<=65;++i)cout<<"cnt["<<i<<"]:"<<cnt[i]<<endl;
    for(int i=1;i<=3000000;++i)pre[i]=pre[i-1]+cnt[i];
    for(int i=1;i<=3000000;++i){
        if(cnt[i]==0)continue;
        if(1ll*i*i>3000000){
            ans[3000000]+=1ll*cnt[i]*(cnt[i]-1)/2;
            ans[3000000]+=1ll*cnt[i]*(pre[3000000]-pre[i]);
            // cout<<i<<" "<<cnt[i]<<" "<<pre[3000000]-pre[i-1]-1<<endl;
            continue;
        }
        ans[i*i]+=1ll*cnt[i]*(cnt[i]-1)/2;
        // if(i*i>=927)cout<<i*i<<" add "<<i<<" "<<i<<" "<<cnt[i]<<" "<<cnt[i]-1<<endl;
        for(int j=i+1;;++j){
            if(1ll*i*j>3000000){
                ans[3000000]+=1ll*cnt[i]*(pre[3000000]-pre[j-1]);
                break;
            }
            // cout<<"ans add: "<<i<<" "<<j<<" "<<cnt[i]*cnt[j]<<endl;
            ans[i*j]+=1ll*cnt[i]*cnt[j];
            // if(i*j>=927)cout<<i*j<<" add "<<i<<" "<<j<<" "<<cnt[i]<<" "<<cnt[j]<<endl;
        }
    }
    // for(int i=0;i<=30;++i)cout<<ans[i]<<" "; cout<<endl;
    for(int i=2999999;i>=1;--i)ans[i]+=ans[i+1];
    // for(int i=1;i<=n;++i)a[i]=rand()%3000000+1,++cnt[a[i]];
    // for(int i=1;i<=3000000;++i)if(cnt[i])num.emplace_back(i,cnt[i]);
    int q; scanf("%d",&q); do{
        int i; scanf("%d",&i);
        printf("%lld\n",ans[i]<<1);
    }while(--q);
}
