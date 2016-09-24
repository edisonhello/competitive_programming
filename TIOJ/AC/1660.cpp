#include<bits/stdc++.h>
using namespace std;

string s;
int i;
bool jizz;
int main(){
    ios_base::sync_with_stdio(0);
    // cin.tie(0);
    while(cin>>s){
        for(i=0;i<(int)s.length()/2;i++){
            if(s[i]!=s[s.length()-1-i]){
                jizz=1;
                cout<<"not palindrome\n";
                break;
            }
        }
        if(!jizz){
            cout<<"palindrome\n";
        }
        jizz=0;
    }
}
