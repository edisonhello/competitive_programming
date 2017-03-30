#include<bits/stdc++.h>
using namespace std;

int mp[255][255];

int main(){
    int n,r;cin>>n>>r;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>mp[i][j];
            mp[i][j]+=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<mp[i+r>n?n:i+r][j+r>n?n:j+r]
                 -mp[i+r>n?n:i+r][j-r-1<0?0:j-r-1]
                 -mp[i-r-1<0?0:i-r-1][j+r>n?n:j+r]
                 +mp[i-r-1<0?0:i-r-1][j-r-1<0?0:j-r-1];
            cout<<(j==n?'\n':' ');
        }
    }
}
// AC
