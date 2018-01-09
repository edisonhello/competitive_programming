#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int n; cin>>n; while(n--){
        string t; cin>>t;
        int A=0,B=0;
        for(int i=0;i<4;++i){
            if(s[i]==t[i])++A;
        }
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                if(i==j)continue;
                if(s[i]==t[j])++B;
            }
        }
        cout<<A<<"A"<<B<<"B"<<endl;
    }
}
