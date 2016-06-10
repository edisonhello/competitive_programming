#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        bool finded = false;
        for(int i=0;i<s.length()/2+1;i++){
            if(s[i]!=s[s.length()-1-i]){
                finded=true;
                cout<<"no"<<endl;
                break;
            }
        }
        if(!finded){
            cout<<"yes"<<endl;
        }
    }
}
