#include<bits/stdc++.h>
using namespace std;

void meow(int n){
    cout<<fixed<<setprecision(12);
    int prv=0,pt=0;
    long long sum=0;
    vector<pair<int,int>> v;
    vector<int> pp;
    while(n--){
        int l,r; cin>>l>>r;
        if(l==r)pp.push_back(l);
        else{
            v.emplace_back(l,1);
            v.emplace_back(r,-1);
        }
    }
    if(v.empty()){
        sort(pp.begin(),pp.end());
        pp.resize(unique(pp.begin(),pp.end())-pp.begin());
        for(int i:pp)++pt,sum+=i;
        double ssum=sum;
        cout<<ssum*ssum/pt/pt<<endl;
        return;
    }
    sort(v.begin(),v.end(),[&](const pair<int,int> &a,const pair<int,int> &b){ return a.first==b.first?a.second>b.second:a.first<b.first; });
    int in=0;
    for(int i=0;i<v.size();++i){
        if(!in)prv=v[i].first;
        in+=v[i].second;
        if(i!=v.size()-1 && v[i+1].first==v[i].first)continue;
        if(!in){
            pt+=v[i].first-prv;
            sum+=(long long)(v[i].first+prv-1)*(v[i].first-prv)/2;
        }
        // cout<<v[i].first<<" "<<prv<<" "<<sum<<endl;
    }
    // cout<<"sum: "<<sum<<endl;
    // cout<<"pt: "<<pt<<endl;
    double ssum=sum+0.5*pt;
    cout<<ssum*ssum/pt/pt<<endl;
}

void solve(){
    int n; cin>>n;
    meow(n); return;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); int t; cin>>t; while(t--){ solve(); } }
