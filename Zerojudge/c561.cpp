#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    int mx=0;
    while(n--){
        string s; cin>>s;
        reverse(s.begin(),s.end());
        stringstream ss(s);
        int t; ss>>t;
        mx=max(mx,t);
    }
    cout<<mx<<endl;
}
