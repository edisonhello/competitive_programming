#include<bits/stdc++.h>
using namespace std;

string s[1231];
int cx[1231],cy[1231],mp[1231][1231];

int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i)cin>>s[i];
    int c=0;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(s[i][j]=='*')++cx[i],++cy[j],++mp[i][j],++c;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        if(cx[i]+cy[j]-mp[i][j]==c){
            cout<<"YES"<<endl;
            cout<<i+1<<" "<<j+1<<endl;
            exit(0);
        }
    }
    cout<<"NO"<<endl;
}
