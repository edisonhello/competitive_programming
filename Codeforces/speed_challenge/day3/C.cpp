#include<bits/stdc++.h>
using namespace std;

bool u[500005];
int main(){
    int n,m; cin>>n>>m;
    if(m>n || !m)return cout<<-1<<endl,0;
    for(int i=1;i<=n;++i)cout<<i<<" "; cout<<endl;
    int now=n+1; u[now]=1;
    for(int c=0;c<n;++c){
        while(now>0 && u[now])now-=m;
        now=max(1,now);
        u[now]=1;
        cout<<now<<" ";
        ++now;
    }
    cout<<endl;
}
