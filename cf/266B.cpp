#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;cin>>n>>t;
    string s;cin>>s;

    for(int i=0;i<t;i++){
        for(int a=n-2;a>=0;a--){
            if(s[a]=='B' && s[a+1]=='G'){
                swap(s[a],s[a+1]);
                a--;
            }
        }
    }

    cout<<s<<endl;
}
