#include<bits/stdc++.h>
using namespace std;

int a[1234][1234];

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>a[i][j];
    cout<<m<<" "<<n<<endl;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j)cout<<a[j][i]<<" ";
        cout<<endl;
    }
}
