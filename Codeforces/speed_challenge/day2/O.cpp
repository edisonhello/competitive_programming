#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    string mp[111];
    for(int i=0;i<n;++i)cin>>mp[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]=='.'){
                if((i+j)&1)mp[i][j]='B';
                else mp[i][j]='W';
            }
        }
        cout<<mp[i]<<endl;
    }
}
