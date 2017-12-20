#include<bits/stdc++.h>
using namespace std;

int cl[3030],sn[3030];
int main(){
    int n,m; cin>>n>>m;
    cl[1]=sn[1]=1;
    for(int i=2;i<=n;++i){
        sn[i]=(sn[i-1]+cl[i-1])%10000;
        for(int j=i-1-m;j>0;--j){
            cl[i]+=cl[j];
        }
        ++cl[i]; cl[i]%=10000;
    }
    cout<<(cl[n]+sn[n])%10000<<endl;
}
