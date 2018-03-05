#include<bits/stdc++.h>
using namespace std;

int main(){
    int ts; cin>>ts; for(int ks=1;ks<=ts;++ks){
        string s; cin>>s>>s;
        int a=0,b=0,w=0,t=0;
        for(char c:s){
            if(c=='A')++a;
            else if(c=='B')++b;
            else if(c=='W')++w;
            else ++t;
        }
        cout<<"Case "<<ks<<": ";
        if(a==s.size()){
            cout<<"ABANDONED"<<endl;
        }
        else if(!w && !t){
            cout<<"BANGLAWASH"<<endl;
        }
        else if(!b && !t){
            cout<<"WHITEWASH"<<endl;
        }
        else if(b>w){
            cout<<"BANGLADESH "<<b<<" - "<<w<<endl;
        }
        else if(w>b){
            cout<<"WWW "<<w<<" - "<<b<<endl;
        }
        else cout<<"DRAW "<<b<<" "<<t<<endl;
    }
}
