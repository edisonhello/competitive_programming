#include<bits/stdc++.h>
using namespace std;

int a[100005];
vector<int> op[100005];
vector<int> dec[100005];
pair<int,int> seg[333];
vector<int> addop[1000005],remop[1000005];
int _val[2500050];
int& val(int x){ return _val[x+1250000]; }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i){
        int l,r; cin>>l>>r;
        seg[i]={l,r};
        addop[l].push_back(i);
        remop[r+1].push_back(i);
        for(int z=l;z<=r;++z)op[z].push_back(i);
    }
    for(int i=1;i<=n;++i)val(a[i])++;
    int mx=-1e7,mn=1e7;
    for(int i=1;i<=n;++i)mx=max(mx,a[i]);
    for(int i=1;i<=n;++i)mn=min(mn,a[i]);
    auto dec=[&](const int i){
        --val(a[i]);
        --a[i];
        ++val(a[i]);
        if(val(mx)==0)--mx;
        if(val(mn-1)!=0)--mn;
    };
    auto inc=[&](const int i){
        --val(a[i]);
        ++a[i];
        ++val(a[i]);
        if(val(mx+1)!=0)++mx;
        if(val(mn)==0)++mn;
    };
    int d=-1e7,at=-1;
    for(int i=1;i<=n;++i){
        for(int j:addop[i]){
            for(int k=seg[j].first;k<=seg[j].second;++k)dec(k);
        }
        for(int j:remop[i]){
            for(int k=seg[j].first;k<=seg[j].second;++k)inc(k);
        }
        int dd=mx-mn;
        if(dd>d)d=dd,at=i;
    }
    cout<<d<<endl;
    cout<<op[at].size()<<endl;
    for(int i:op[at])cout<<i<<" "; cout<<endl;

}
