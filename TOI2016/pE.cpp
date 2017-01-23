#include<string>
#include<iostream>
#include<sstream>
#include<stack>
#include<vector>
#include<cmath>
#define pb(x) push_back(x)
using namespace std;
#define ll long long
#define ld long double

void goInt(string s){
    stringstream ss(s);
    unsigned ll n;ss>>n;
    stack<char> sk;
    if(n==0){
        sk.push('0');
    }
    while(n){
        if(n&1)sk.push('1');
        else sk.push('0');
        n>>=1;
    }
    while(sk.size()){
        cout<<sk.top();sk.pop();
    }
}
void goFlt(string s){
    stringstream ss(s);
    vector<char> v;
    vector<ll> r;
    ll n,md=pow(10ll,(int)s.length());ss>>n;

    int pos=0,repp=-1;
    while(1){
        if(n==0)break;
        for(int i=0;i<pos;++i){
            if(r[i]==n){
                repp=i;
                break;
            }
        }
        if(~repp)break;
        r.pb(n);
        n<<=1;++pos;
        if(n/md){
            n%=md;
            v.pb('1');
        }
        else{
            v.pb('0');
        }
    }
    // cout<<repp<<endl;
    if(~repp){
        for(auto i=0u;i<v.size();++i){
            if((int)i==repp)cout<<"(";
            cout<<v[i];
        }
        cout<<")";
    }
    else{
        for(auto c:v)cout<<c;
    }
}

int main(){
    string s;cin>>s;
    auto pos=s.find('.');
    if(pos==string::npos){
        goInt(s);
        cout<<endl;
    }
    else{
        goInt(s.substr(0,pos));
        cout<<".";
        goFlt(s.substr(pos+1,s.length()-1-pos));
        cout<<endl;
    }
}
