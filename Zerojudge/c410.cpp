#include<bits/stdc++.h>
using namespace std;

bitset<6500006> wait;
int main(){
    int n; cin>>n;
    queue<int> q; for(int i=0,t;i<n;++i)cin>>t,q.push(t);
    int ans=0,now=0; for(int i=0,t;i<n;++i){
        cin>>t; ++now; ans=max(ans,now);
        wait[t]=1;
        while(q.size() && wait[q.front()]){
            q.pop(); --now;
        }
    } cout<<ans<<endl;
}
