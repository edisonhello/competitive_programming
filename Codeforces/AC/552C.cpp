#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll w,m;
vector<ll> fama;

void dfs(int now,ll val){
    if(val==m){ exit((cout<<"YES"<<endl,0)); }
    if(now>=int(fama.size()))return;
    dfs(now+1,val+fama[now]);
    dfs(now+1,val-fama[now]);
    dfs(now+1,val);
}

int main(){
    cin>>w>>m;
    if(w<=3){ exit((cout<<"YES"<<endl,0)); }
    ll ww=1; while(ww<=1e9)fama.push_back(ww),ww*=w;
    fama.push_back(ww);
    dfs(0,0);
    cout<<"NO"<<endl;
}
