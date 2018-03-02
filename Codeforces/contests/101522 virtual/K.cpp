#include<bits/stdc++.h>
using namespace std;

int kgt[123][123];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    for(int i=0;i<k;++i){
        int x,y; cin>>x>>y;
        kgt[x][y]=1;
    }
    if(n==1 && m==1)return cout<<(1-k)<<endl,0;
    if(n==1)return cout<<(2-kgt[1][1]-kgt[1][m])<<endl,0;
    if(m==1)return cout<<(2-kgt[1][1]-kgt[n][1])<<endl,0;
    return cout<<(4-kgt[1][1]-kgt[1][m]-kgt[n][1]-kgt[n][m])<<endl,0;
}
