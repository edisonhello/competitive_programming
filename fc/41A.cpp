#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;cin>>a>>b;

    for(int i=0;i<a.length();i++){
        if(a[i]!=b[a.length()-1-i]){
            cout<<"NO"<<endl;return 0;
        }
    }
    cout<<"YES"<<endl;return 0;
}
