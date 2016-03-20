#include<bits/stdc++.h>

using namespace std;
int main(){
    string n;cin>>n;
    int now=0;
    char a[5]={'h','e','l','l','o'};
    for(int i=0;i<n.length();i++){
        if(n[i]==a[now]){
            now++;
        }
    }
    if(now==5)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
