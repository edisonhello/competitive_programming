#include<bits/stdc++.h>
using namespace std;

string bd[111],pt[111];
int bdbs[111],ptbs[111];

int main(){
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;++i)cin>>bd[i];
    for(int i=0;i<n;++i)cin>>pt[i];
    int ans=0;
    for(int j=0;j<m;++j){
        for(int i=0;i<n;++i){
            if(bd[i][j]=='A')bdbs[j]|=1;
            if(bd[i][j]=='T')bdbs[j]|=(1<<1);
            if(bd[i][j]=='C')bdbs[j]|=(1<<2);
            if(bd[i][j]=='G')bdbs[j]|=(1<<3);
            if(pt[i][j]=='A')ptbs[j]|=1;
            if(pt[i][j]=='T')ptbs[j]|=(1<<1);
            if(pt[i][j]=='C')ptbs[j]|=(1<<2);
            if(pt[i][j]=='G')ptbs[j]|=(1<<3);
        }
        if(bdbs[j]&ptbs[j])continue;
        ++ans;
    }
    cout<<ans<<endl;
}
