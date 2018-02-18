#include<bits/stdc++.h>
using namespace std;

#define v(x) (x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='y')

int main(){
    string s; cin>>s>>s;
    char prv=s[0];
    for(auto i=1u;i<s.size();++i){
        if(v(prv) && v(s[i]))continue;
        cout<<prv;
        prv=s[i];
    }
    cout<<prv<<endl;
}
