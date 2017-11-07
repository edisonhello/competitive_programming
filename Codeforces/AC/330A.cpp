#include<bits/stdc++.h>
using namespace std;
#define s mp

int n,m; string  mp[12];
bool eat[12][12];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    for(int i=0;i<n;++i){
        bool ok=1;
        for(int j=0;j<m;++j){
            if(s[i][j]=='S')ok=0;
        }
        if(ok)for(int j=0;j<m;++j)eat[i][j]=1;
    }
    for(int i=0;i<m;++i){
        bool ok=1;
        for(int j=0;j<n;++j){
            if(s[j][i]=='S')ok=0;
        }
        if(ok)for(int j=0;j<n;++j)eat[j][i]=1;
    }
    int ans=0;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(eat[i][j])++ans; cout<<ans<<endl;
}
