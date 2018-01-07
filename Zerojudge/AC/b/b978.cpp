#include<bits/stdc++.h>
using namespace std;

int main(){
    char c[103];
    string s; while(cin>>s){
        for(char sc:s){
            int t; cin>>t; 
            c[t]=sc;
        }
        for(int i=1;i<=s.size();++i)cout<<c[i];
        cout<<endl;
    }
}
