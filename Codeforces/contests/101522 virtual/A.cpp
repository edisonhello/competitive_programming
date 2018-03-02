#include<bits/stdc++.h>
using namespace std;

int d[100005];
int main(){
    int m; cin>>m;
    for(int i=0;i<m;++i)cin>>d[i];
    sort(d,d+m);
    long long ans=0;
    for(int i=0;i<m;++i){
        // cout<<"i: "<<i<<endl;
        // int right=min(m-i-1,d[i]);
        // cout<<right<<endl;
        // ans+=max(0,right-i)*2ll;
        int it=lower_bound(d,d+i,i+1)-d;
        if(it==i)continue;
        // cout<<"it: "<<it<<endl;
        ans+=i-it;
        // cout<<i-it<<endl;
    }
    cout<<ans*2<<endl;
}
