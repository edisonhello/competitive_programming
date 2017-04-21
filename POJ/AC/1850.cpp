#include<string>
#include<iostream>
using namespace std;
#define ll long long

bool jizz(string &s,int n){
    for(int i=0;i<n-1;++i){
        if(s[i+1]<=s[i])return 1;
    } return 0;
}
ll C[28][28];
void init(){
    for(int i=1;i<=27;++i)C[i][i]=1,C[i][0]=1;
    for(int i=2;i<=27;++i){
        for(int j=1;j<i;++j)C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
}
ll _C(int i,int j){
    if(j>i)return 0;
    return C[i][j];
}
void meow(string &s){
    int n=s.length();
    if(jizz(s,n)){
        cout<<0<<endl;
        return;
    }
    ll ans=0;
    for(int i=1;i<n;++i)ans+=_C(26,i);
    for(int i=0;i<n;++i){
        for(int j=(i?s[i-1]+1:'a');j<s[i];++j){
            ans+=_C(25-(j-'a'),n-1-i);
        }
    }
    cout<<ans+1<<endl;
}

int main(){
    init();
    string s;while(cin>>s){
        if(s=="0")break;
        meow(s);
    }
}
