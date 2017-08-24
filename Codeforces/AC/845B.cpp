#include<bits/stdc++.h>
using namespace std;
#define F(x) for(int x='0';x<='9';++x)
int main(){
    string s; cin>>s; int mn=87;
    F(a)F(b)F(c)F(d)F(e)F(f){
        string ss; ss+=a; ss+=b; ss+=c; ss+=d; ss+=e; ss+=f;
        if(a+b+c!=d+e+f)continue;
        int upd=0;
        for(int i=0;i<6;++i)if(s[i]!=ss[i])++upd;
        mn=min(mn,upd);
    } cout<<mn<<endl;
}
