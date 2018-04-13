#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> gof[1000006],byf[1000006];
long long gco[1000006],bco[1000006],nmn[1000006];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    while(m--){
        int d,f,t,c;
        cin>>d>>f>>t>>c;
        if(t==0)gof[d].push_back({f,c});
        else byf[d].push_back({t,c});
    }
    long long now=0;
    for(int i=1;i<=n;++i){
        nmn[i]=1e12;
        now+=1e12;
    }
    for(int i=0;i<=1000003;++i){
        for(auto p:gof[i]){
            if(p.second<nmn[p.first]){
                now-=nmn[p.first]-p.second;
                nmn[p.first]=p.second;
            }
        }
        gco[i]=now;
    }
    now=0;
    for(int i=1;i<=n;++i){
        nmn[i]=1e12;
        now+=1e12;
    }
    for(int i=1000003;i>=0;--i){
        for(auto p:byf[i]){
            if(p.second<nmn[p.first]){
                now-=nmn[p.first]-p.second;
                nmn[p.first]=p.second;
            }
        }
        bco[i]=now;
    }
    now=1ll<<60;
    for(int i=0;i+k+1<=1000003;++i){
        now=min(now,gco[i]+bco[i+k+1]);
    }
    if(now>=1e12)now=-1;
    cout<<now;
}
