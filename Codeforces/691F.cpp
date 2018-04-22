#include<bits/stdc++.h>
using namespace std;

int a[1000006],cnt[3000006],cpre[1000006],rec[3000006];
vector<pair<int,int>> num;

int main(){
    srand(time(0));
    memset(rec,0xff,sizeof(rec));
    // int n; scanf("%d",&n);
    int n=10000;
    // for(int i=1;i<=n;++i)scanf("%d",&a[i]),++cnt[a[i]];
    for(int i=1;i<=n;++i)a[i]=rand()%3000000+1,++cnt[a[i]];
    for(int i=1;i<=3000000;++i)if(cnt[i])num.emplace_back(i,cnt[i]);
    for(int i=0;i<num.size();++i)cpre[i]=num[i].second+(i?cpre[i-1]:0); cpre[num.size()]=cpre[num.size()-1];
    // int q; scanf("%d",&q); do{
    int q=3000000; do{
        // int x,ptr=num.size(); scanf("%d",&x); long long ans=0;
        int x=rand()%300000+1,ptr=num.size(); long long ans=0;
        if(rec[x]<0){
            for(int i=0;i<num.size();++i){
                int xx=num[i].first;
                // cout<<"now i "<<i<<" , "<<xx<<endl;
                if(1ll*xx*xx>=x){
                    // cout<<"exceed"<<endl;
                    ans+=1ll*(cpre[num.size()]-(i?cpre[i-1]:0))*(cpre[num.size()]-(i?cpre[i-1]:0)-1)/2;
                    break;
                }
                // cout<<" limit value : "<<(((x-1)/xx)+1)<<endl;
                // int ptr=lower_bound(num.begin()+i+1,num.end(),pair<int,int>(((x-1)/xx)+1,-1))-num.begin();
                while(1ll*xx*num[ptr-1].first>=x)--ptr;
                // cout<<"ptr is "<<ptr<<" , with val "<<num[ptr].first<<endl;
                // cout<<"answer += "<<num[i].second<<" * "<<(cpre[num.size()]-(ptr?cpre[ptr-1]:0))<<endl;
                ans+=1ll*num[i].second*(cpre[num.size()]-(ptr?cpre[ptr-1]:0));
            }
            rec[x]=ans;
        }
        else ans=rec[x];
        printf("%lld\n",ans<<1);
    }while(--q);
}
