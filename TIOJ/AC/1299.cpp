#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    while(cin>>s){
        int a=0;
        for(int i=0;i<(int)s.length();i++){
            if(s[i]>='a')s[i]-=32;
            a+=s[i]-'A'+1;
        }
        a%=17;
        if(a<3)cout<<"D\n";
        else if(a<6)cout<<"C\n";
        else if(a<10)cout<<"B\n";
        else if(a<13)cout<<"A\n";
        else cout<<"SA\n";
    }
}
