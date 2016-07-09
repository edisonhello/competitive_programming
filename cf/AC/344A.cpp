#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;


    int cnt=1;
    vector<string> s;
    s.resize(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1])cnt++;
    }
    cout<<cnt<<endl;
}
