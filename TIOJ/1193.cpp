#include<bits/stdc++.h>
using namespace std;
long long n,m,a,i;
int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n>>m && n){
        a=1;
        for(i=2;i<=n;i++){
            if(m%i==0){
                m/=i;
                if(m==1){
                    cout<<"0\n";
                    goto f;
                }
            }
            // cout<<a<<" "<<i<<'\n';
            a*=i;
            // cout<<a<<" "<<i<<'\n';
            a%=m;
            // cout<<a<<" "<<i<<'\n';
        }
        cout<<a<<'\n';
        f:;
    }
}
