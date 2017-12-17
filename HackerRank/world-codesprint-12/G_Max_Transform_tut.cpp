#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

int a[200005],l[200005],r[200005];
ll c2p[500005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(ll i=2;i<500005;++i)c2p[i]=(c2p[i-1]+i*(i-1)/2)%mod;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i]; a[0]=a[n+1]=10000007;
    stack<int> st; st.push(0);
    for(int i=1;i<=n;++i){
        while(a[st.top()]<a[i])st.pop();
        l[i]=i-st.top();
        st.push(i);
    }
    while(st.size())st.pop(); st.push(n+1);
    for(int i=n;i>=1;--i){
        while(a[st.top()]<a[i])st.pop();
        r[i]=st.top()-i;
        st.push(i);
    }
    for(int i=1;i<=n;++i)cout<<l[i]<<" "<<r[i]<<endl;
    ll ans=0;
    for(int i=1;i<=n;++i){
        cout<<"count: "<<c2p[l[i]+r[i]]-c2p[l[i]]-c2p[r[i]]<<endl;
        ans=ans+(c2p[l[i]+r[i]]-c2p[l[i]]-c2p[r[i]])%mod*a[i]%mod;
    }
    cout<<((ans%mod+mod)%mod)<<endl;
}
// tutorial don't understand(?)
