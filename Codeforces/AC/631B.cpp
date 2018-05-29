#include<bits/stdc++.h>
using namespace std;

int rt[5005],ra[5005],ct[5005],ca[5005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=k;++i){
        int t,j,a; cin>>t>>j>>a;
        (t==1?rt:ct)[j]=i;
        (t==1?ra:ca)[j]=a;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cout<<(rt[i]>ct[j]?ra[i]:ca[j])<<" ";
        }
        cout<<endl;
    }
}
