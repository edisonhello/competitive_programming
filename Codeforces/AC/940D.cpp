#include<bits/stdc++.h>
using namespace std;

int a[100005],L=-1000000000,R=1000000000;
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    string s; cin>>s;
    for(int i=4;i<n;++i){
        if(s[i]!=s[i-1] && s[i]!=s[i-2] && s[i]!=s[i-3] && s[i]!=s[i-4]){
            if(s[i]=='1'){
                L=max({L,max({a[i],a[i-1],a[i-2],a[i-3],a[i-4]})+1});
            }
            else R=min({R,min({a[i],a[i-1],a[i-2],a[i-3],a[i-4]})-1});
        }
    }
    cout<<L<<" "<<R<<endl;
}
