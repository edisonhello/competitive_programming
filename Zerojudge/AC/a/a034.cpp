#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;while(cin>>n){
        string s;
        while(n){
            s=((n&1?"1":"0"))+s;
            n>>=1;
        }
        cout<<s<<endl;
    }
}
