#include<bits/stdc++.h>
using namespace std;

int a[5665];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    bool ok=0;
    for(int i=1;i<=n;++i){
        int b=a[i];
        int c=a[b];
        if(a[c]==i)ok=1;
    }
    cout<<(ok?"YES":"NO")<<endl;
}
