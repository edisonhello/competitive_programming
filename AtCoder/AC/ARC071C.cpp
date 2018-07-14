#include<bits/stdc++.h>
using namespace std;

// #include</home/edison/Coding/cpp/template/debug.cpp>

int spre[100005],tpre[100005];

int main(){
    string s,t; cin>>s>>t;
    for(int i=1;i<=s.size();++i)spre[i]=spre[i-1]+(s[i-1]=='A');
    for(int i=1;i<=t.size();++i)tpre[i]=tpre[i-1]+(t[i-1]=='A');
    auto csa=[&](int l,int r){ return spre[r]-spre[l-1]; };
    auto csb=[&](int l,int r){ return r-l+1-spre[r]+spre[l-1]; };
    auto cta=[&](int l,int r){ return tpre[r]-tpre[l-1]; };
    auto ctb=[&](int l,int r){ return r-l+1-tpre[r]+tpre[l-1]; };
    int q; cin>>q; while(q--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        // PDE(csa(a,b),csb(a,b),cta(c,d),ctb(c,d));
        if((csa(a,b)+csb(a,b)*2)%3==(cta(c,d)+ctb(c,d)*2)%3)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
