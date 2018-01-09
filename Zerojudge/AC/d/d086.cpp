#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; while(cin>>s){
        if(s=="0")break;
        int pts=0;
        bool fail=0;
        for(char c:s){
            if(c>='A' && c<='Z')c=c-'A'+'a';
            if(!(c>='a' && c<='z'))fail=1;
            pts+=c-'a'+1;
        }
        if(fail)cout<<"Fail"<<endl;
        else cout<<pts<<endl;
    }
}
