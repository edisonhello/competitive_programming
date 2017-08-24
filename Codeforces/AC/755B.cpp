#include<set>
#include<iostream>
using namespace std;

set<string> st;

int main(){
    int n,m;cin>>n>>m;
    int ni=0,mi=0,pb=0;
    while(n--){
        string s;cin>>s;
        st.insert(s);
        ++ni;
    }
    while(m--){
        string s;cin>>s;
        if(st.find(s)!=st.end())--ni,++pb;
        else ++mi;
    }
    //cout<<ni<<mi<<pb<<endl;
    ni-=mi;mi=0;if(ni<0)mi=-ni,ni=0;
    pb%=2;
    // cout<<ni<<""<<mi<<" "<<pb<<endl;
    if(pb+ni<=mi)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
