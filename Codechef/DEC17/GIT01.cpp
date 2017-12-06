#include<bits/stdc++.h>
using namespace std;

string mp[122],cs1[122],cs2[122];
int main(){
    for(int i=0;i<122;++i)cs1[0]+=i&1?"G":"R",cs2[0]+=i&1?"R":"G";
    for(int i=1;i<122;++i)cs1[i]=cs2[i-1],cs2[i]=cs1[i-1];
    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        for(int i=0;i<n;++i)cin>>mp[i];
        int cost1=0,cost2=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mp[i][j]!=cs1[i][j])cost1+=cs1[i][j]=='G'?5:3;
                if(mp[i][j]!=cs2[i][j])cost2+=cs2[i][j]=='G'?5:3;
            }
        }
        cout<<min(cost1,cost2)<<endl;
    }
}
// AC 100
