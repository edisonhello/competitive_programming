#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[300008];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    while(q--){
        int l,r; cin>>l>>r;
        r=min(r,l+95);
        vector<pair<ll,int>> st;
        for(int i=l;i<=r;++i){
            st.emplace_back(a[i],i);
        }
        sort(st.begin(),st.end());
        bool ok=0;
        for(int i=2;i<st.size();++i){
            if(st[i-2].first+st[i-1].first>st[i].first){
                ok=1;
                cout<<st[i-2].second<<" "<<st[i-1].second<<" "<<st[i].second<<endl;
                break;
            }
        }
        if(!ok)cout<<-1<<endl;
    }
}
