#include<bits/stdc++.h>
using namespace std;

string mp[111];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>mp[i],mp[i]="x"+mp[i]+"x";
    for(int i=0;i<=n+1;++i)mp[0]+='x',mp[n+1]+='x';
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
        int cnt=0;
        if(mp[i-1][j]=='o')++cnt;
        if(mp[i+1][j]=='o')++cnt;
        if(mp[i][j-1]=='o')++cnt;
        if(mp[i][j+1]=='o')++cnt;
        if(cnt&1)return cout<<"NO"<<endl,0;
    } cout<<"YES"<<endl;
}
