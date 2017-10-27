#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    s+=s;
    for(int i=0;i<n;i++){
        cout<<s.substr(i,n)<<endl;
    }
}
