#include<bits/stdc++.h>
using namespace std;

int bea[300005];
bitset<300005> isim;
map<int,pair<int,int>> mp;
long long pre[300005],suf[300005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    long long tot=0;
    for(int i=1;i<=n;++i){
        cin>>bea[i];
        auto it=mp.find(bea[i]);
        if(it==mp.end())mp[bea[i]]=pair<int,int>(i,i);
        else it->second.second=i;
    }
    for(const auto &it:mp){
        isim[it.second.second]=1;
        isim[it.second.first]=1;
    }
    vector<int> jizz;
    for(int i=1;i<=n;++i)if(bea[i]<0)bea[i]=0,jizz.push_back(i);else tot+=bea[i];
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+bea[i];
    for(int i=n;i>=1;--i)suf[i]=suf[i+1]+bea[i];
    long long ans=-1e18-87;
    pair<int,int> rec;
    int lrv=0;
    for(auto it:mp){
        if(it.second.first==it.second.second)continue;
        long long dans=0;
        if(it.first<0)dans+=2*it.first;
        if(tot-pre[it.second.first-1]-suf[it.second.second+1]+dans>ans){
            ans=tot-pre[it.second.first-1]-suf[it.second.second+1]+dans;
            rec=it.second;
            lrv=it.first;
        }
    }
    // cout<<rec.first<<" "<<rec.second<<endl;
    for(int i=1;i<rec.first;++i)if(bea[i]>0)jizz.push_back(i);
    for(int i=n;i>rec.second;--i)if(bea[i]>0)jizz.push_back(i);
    cout<<ans<<" "<<jizz.size()-(lrv<0?2:0)<<endl;
    for(const int &i:jizz)if(i!=rec.first && i!=rec.second)cout<<i<<" "; cout<<endl;
}
