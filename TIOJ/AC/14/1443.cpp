#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#define ld long double
using namespace std;

inline void add(string &s){
    int ptr=(int)s.size()-1;
    ++s[ptr];
    while(ptr && s[ptr]>'9'){
        s[ptr]='0';
        ++s[--ptr];
    }
    if(s[0]>'9'){
        s[0]='0';
        s.insert(0,1,'1');
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;add(s);
    ld ans;
    ans=(ld)((int)s.length()-1);
    stringstream ss;
    ss<<s[0];
    ss<<'.';
    ss<<s.substr(1,30);
    ld sml;
    ss>>sml;
    // cout<<ans<<"+"<<sml<<endl;
    ans+=(ld)log10(sml);
    ans/=(ld)log10(2);
    cout<<(int)(ans+0.00000001)<<endl;
}
