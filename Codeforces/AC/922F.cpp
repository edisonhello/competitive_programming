#include<bits/stdc++.h>
using namespace std;

int deg[300005];
bitset<300005> np,bye;


int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i){
        for(int j=i*2;j<=n;j+=i)++deg[j];
    }
    np[0]=np[1]=1;
    for(int i=2;i<=n;++i){
        for(int j=i*2;j<=n;j+=i)np[j]=1;
    }
    int now=0;
    for(int i=2;i<=n;++i){
        now+=deg[i];
        if(now>=k){
            n=i;
            break;
        }
    }
    // cout<<"new n is "<<n<<endl;
    if(now<k)exit((cout<<"No"<<endl,0));
    set<pair<int,int>> ho;
    for(int i=2;i<=n;++i)if(!np[i])ho.insert({n/i,i});
    // cout<<ho.size()<<endl;
    while(now>k){
        auto it=--ho.upper_bound({now-k,1<<30});
        bye[it->second]=1;
        now-=it->first;
        ho.erase(it);
    }
    cout<<"Yes"<<endl;
    cout<<n-bye.count()<<endl;
    for(int i=1;i<=n;++i)if(!bye[i])cout<<i<<" ";
}
