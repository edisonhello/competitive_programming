#include<bits/stdc++.h>
using namespace std;

string l[3]={"qwertyuiop","asdfghjkl;","zxcvbnm,./"};

int main(){
    string s; cin>>s;
    if(s=="L"){
        cin>>s;
        for(char c:s){
            for(int i=0;i<3;++i){
                for(int j=0;j<l[i].length();++j){
                    if(l[i][j]==c)cout<<l[i][j+1];
                }
            }
        }
    }
    else{
        cin>>s;
        for(char c:s){
            for(int i=0;i<3;++i){
                for(int j=0;j<l[i].length();++j){
                    if(l[i][j]==c)cout<<l[i][j-1];
                }
            }
        }
    }
}
