#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;

    int ans=0;
    for(int i=0;i<a.length();i++){
        if(a[i]=='4'||a[i]=='7'){
            ans++;
        }
    }
    if(ans==4||ans==7){
        cout<<"YES"<<endl;
    }else{cout<<"NO"<<endl;}
}
