#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,i;
    string jizz;
    while(cin>>n && n){
        getline(cin,jizz);
        getline(cin,jizz);
        for(i=1;i<=n;i++){
            if(i-1)cout<<' ';
            cout<<i;
        }
        cout<<'\n';
    }
}
