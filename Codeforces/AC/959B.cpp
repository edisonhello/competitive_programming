#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;
int a[100005],djs[100005];
int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,m; cin>>n>>k>>m;
    for(int i=1;i<=n;++i){
        string s; cin>>s;
        mp[s]=i;
        djs[i]=i;
    }
    for(int i=1;i<=n;++i)cin>>a[i];
    while(k--){
        int x; cin>>x;
        --x; int prv; cin>>prv; 
        while(x--){
            int nw; cin>>nw;
            nw=F(nw); prv=F(prv);
            if(a[nw]<a[prv])djs[prv]=nw;
            else djs[nw]=prv;
        }
    }
    long long tot=0;
    for(int i=1;i<=m;++i){
        string s; cin>>s;
        int id=mp[s];
        tot+=a[F(id)];
    }
    cout<<tot<<endl;
}
