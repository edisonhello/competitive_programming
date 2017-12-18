#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    string s; cin>>s;
    while(m--){
        int l,r; char a,b; cin>>l>>r>>a>>b;
        --l; for(int i=l;i<r;++i)if(s[i]==a)s[i]=b;
    }
    cout<<s<<endl;

}
