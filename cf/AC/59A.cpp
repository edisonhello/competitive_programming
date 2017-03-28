#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int up=0,sm=0;
    for(char c:s){
        if(c<='Z')++up;
        else ++sm;
    }
    if(up>sm){
        for(char &c:s){
            if(c>='a')c^=32;
        }
        cout<<s<<endl;
    }
    else{
        for(char &c:s){
            if(c<='Z')c^=32;
        }
        cout<<s<<endl;
    }
}
