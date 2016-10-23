#include<bits/stdc++.h>
using namespace std;
int n,a[15],s[15];

int hn(int lv){
    if(lv==1)return a[1];
    if(s[lv])return s[lv];
    return s[lv]=hn(lv-1)*2+a[lv];
}

int main(){
    ios_base::sync_with_stdio(0);
    while(cin>>n){
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        memset(s,0,sizeof(s));
        cout<<hn(n)<<'\n';
    }
}
