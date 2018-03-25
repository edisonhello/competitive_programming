#include<bits/stdc++.h>
using namespace std;


int mp[30][30];
int main(){
    int n; cin>>n;
    memset(mp,-1,sizeof(mp));
    for(int i=0;i<=2*n+1;++i){
        for(int j=0;j<=n*2+1;++j){
            if(abs(i-n)+abs(j-n)<=n){
                mp[i][j]=n-abs(i-n)-abs(j-n);
            }
        }
    }
    for(int i=0;i<n*2+1;++i){
        for(int j=0;j<n*2+1;++j){
            if(mp[i][j]==-1)cout<<"  ";
            else cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }
}
