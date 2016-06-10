#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int d='p'-'i';
    while(getline(cin,s)){
        for(int i=0;i<s.length();i++){
            s[i]-=d;
        }
        cout<<s<<endl;
    }
}
