#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; string s; while(cin>>n,n){
        cin>>s;
        n=s.size()/n;
        for(int i=0,j=n;j<=s.size();i+=n,j+=n){
            reverse(s.begin()+i,s.begin()+i+n);
        }
        cout<<s<<endl;
    }
}
