#include<bits/stdc++.h>
using namespace std;

int a[10000007];
deque<int> dq;

int main(){
    int n,k,t,b,c,p; cin>>n>>k>>t>>a[0]>>b>>c>>p;
    for(int i=1;i<=n;++i)a[i]=(1ll*a[i-1]*b+c)%p;
    // for(int i=1;i<=n;++i)cout<<a[i]<<" "; cout<<endl;
    long long ans=0;
    int rptr=0;
    for(int i=1;i<=n;++i){
        while(dq.size()<k && rptr<n){
            ++rptr;
            if(a[rptr]>=t)dq.push_back(rptr);
        }
        if(dq.size()>=k)ans+=n-rptr+1;
        // cout<<i<<" "<<dq.size()<<" "<<rptr<<endl;
        if(dq.size() && dq.front()==i)dq.pop_front();
    }
    cout<<ans<<endl;
}
