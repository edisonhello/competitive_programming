#include<bits/stdc++.h>
using namespace std;
int n,k,i;
string s;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n>>k){
        for(i=0;i<n;i++){
            cin>>s;
            if(i==n-k){
                cout<<s<<'\n';
            }
        }
    }
}
