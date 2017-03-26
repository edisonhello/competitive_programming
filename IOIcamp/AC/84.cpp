#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long
#define ld long double

using namespace std;

int dg[100055];

int main(){
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;
        memset(dg,0,sizeof(int)*(n+5));
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            ++dg[u],++dg[v];
        }
        if(n==2){cout<<1<<endl;continue;}
        int ans=0;
        for(int i=1;i<=n;++i)if(dg[i]==1)++ans;
        cout<<ans<<endl;
    }
}
