#include<bits/stdc++.h>
using namespace std;
#define ll long long

multiset<pair<ll,int>> st;

ll a[50005];
vector<ll> b;
int nxt[50005],prv[50005];

void ers(int id){
    nxt[prv[id]]=nxt[id];
    prv[nxt[id]]=prv[id];
}

int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    if(a[0]>=0)b.push_back(-(1ll<<50));
    for(int i=0,j;i<n;i=j){
        for(j=i;j<n;++j){
            if((a[i]>=0 && a[j]<0) || (a[i]<0 && a[j]>=0))break;
        }
        ll sum=0;
        for(int k=i;k<j;++k)sum+=a[k];
        b.push_back(sum);
    }
    if(b.back()>0)b.push_back(-(1ll<<50));
    else b[b.size()-1]=-(1ll<<50);
    b[0]=-(1ll<<50);

    // for(ll i:b)cout<<i<<" "; cout<<endl;

    ll ans=0;
    int cho=0;
    for(int i=1;i+1<b.size();++i){
        if(b[i]>=0)ans+=b[i],++cho;
        st.insert({abs(b[i]),i});
    }
    for(int i=0;i<b.size();++i)nxt[i]=i+1,prv[i]=i-1;
    while(cho>m){
        auto it=*st.begin();
        st.erase(st.begin());
        // cout<<it.first<<" "<<it.second<<endl;
        ans-=it.first;
        int id=it.second;
        int pid=prv[it.second];
        int nid=nxt[it.second];
        b[id]+=b[pid]+b[nid];
        // cout<<"b4 ers "<<st.size()<<endl;
        st.erase({abs(b[pid]),pid});
        st.erase({abs(b[nid]),nid});
        // cout<<"af ers "<<st.size()<<endl;
        st.insert({abs(b[id]),id});
        ers(pid); ers(nid);
        --cho;
    }
    cout<<ans<<endl;
}

