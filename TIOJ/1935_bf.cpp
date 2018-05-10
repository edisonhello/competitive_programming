#include<bits/stdc++.h>
using namespace std;

vector<int> pos;
vector<pair<int,int>> crs;
int pcnt[200005],scnt[200005];
long long pre[200005],suf[200005],ans=1ll<<60;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>k>>n;
    long long delta=0;
    for(int i=1;i<=n;++i){
        char p,q; int s,t; cin>>p>>s>>q>>t;
        delta+=abs(t-s);
        if(p!=q)++delta,crs.emplace_back(s,t),pos.push_back(s),pos.push_back(t);
    }
    pos.push_back(0);
    sort(pos.begin(),pos.end()); pos.resize(unique(pos.begin(),pos.end())-pos.begin());
    for(auto &p:crs){
        int mn=p.first,mx=p.second; if(mn>mx)swap(mn,mx);
        // cout<<mn<<" "<<mx<<endl;
        mn=lower_bound(pos.begin(),pos.end(),mn)-pos.begin();
        mx=lower_bound(pos.begin(),pos.end(),mx)-pos.begin();
        // pre[mx]+=abs(p.first-p.second);
        // suf[mn]+=abs(p.first-p.second);
        ++pcnt[mx]; ++scnt[mn];
    }
    for(int i=1;i<pos.size();++i){
        pre[i]+=pre[i-1]+pcnt[i-1]*2ll*(pos[i]-pos[i-1]);
        pcnt[i]+=pcnt[i-1];
    }
    for(int i=pos.size()-2;i>=0;--i){
        suf[i]+=suf[i+1]+scnt[i+1]*2ll*(pos[i+1]-pos[i]);
        scnt[i]+=scnt[i+1];
    }
    // for(int i=0;i<pos.size();++i)cout<<i<<" "<<pre[i]<<" "<<suf[i]<<endl;
    // cout<<"delta: "<<delta<<endl;
    if(k==1){
        for(int i=0;i<pos.size();++i){
            ans=min(ans,pre[i]+suf[i]);
        }
        cout<<ans+delta<<endl;
    }
    else{
        for(int i=0;i<pos.size();++i){
            for(int j=i;j<pos.size();++j){
                ans=min(ans,pre[i]+suf[j]);
            }
        }
        cout<<ans+delta<<endl;
    }
}
