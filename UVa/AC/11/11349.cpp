#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[111][111];

main(){
    int ts,ks=0;cin>>ts;
    while(ts--){
        int n;
        string s;cin>>s>>s>>n;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin>>a[i][j];
            }
        }
        bool jiz=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(a[i][j]<0)jiz=1;
                if(a[i][j]!=a[n-i-1][n-j-1])jiz=1;
            }
        }
        cout<<"Test #"<<(++ks)<<": ";
        if(jiz)cout<<"Non-symmetric.\n";
        else cout<<"Symmetric.\n";
    }
}
