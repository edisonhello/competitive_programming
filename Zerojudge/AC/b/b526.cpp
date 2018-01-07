#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    set<int> st;
    st.insert(1);
    st.insert(n+1);
    int m; cin>>m;
    while(m--){
        int l,r; cin>>l>>r; ++r;
        if(st.find(l)!=st.end())st.erase(l);
        else st.insert(l);
        if(st.find(r)!=st.end())st.erase(r);
        else st.insert(r);
    }
    int ans=0,sf=0,prv=1;
    for(int i:st){
        ans+=sf*(i-prv);
        sf^=1;
        prv=i;
    }
    cout<<ans<<endl;
}
