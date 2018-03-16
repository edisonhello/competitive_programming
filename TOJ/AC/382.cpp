#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll x[300005];
ll mem[300005];
int c[300005];
int dead[300005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n,k; cin>>t>>n>>k;
    for(int i=1;i<=t;++i)cin>>c[i];
    for(int i=1;i<=n;++i)cin>>mem[i];
    while(k--){
        int l,r; ll u; cin>>l>>r>>u;
        x[l]+=u;
        x[r+1]-=u;
    }
    ll now=0;
    for(int i=1;i<=t;++i){
        now+=x[i];
        if(now>mem[c[i]]){
            if(!dead[c[i]])dead[c[i]]=i;
        }
        else mem[c[i]]-=now;
    }
    bool alive=0;
    for(int i=1;i<=n;++i)if(!dead[i])dead[i]=-1,alive=1;
    cout<<(alive?"Normal":"Hoo Lan")<<endl;
    for(int i=1;i<=n;++i)cout<<dead[i]<<" \n"[i==n];
}
