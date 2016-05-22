#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;cin>>a;
    sort(a.begin(),a.end());
    int i,j,n=a.length();
    for(i=0;i<a.length();i=j){
        for(j=i+1;a[i]==a[j];j++){
            n--;
        }
    }
    if(n&1){
        cout<<"IGNORE HIM!"<<endl;
    }else{
        cout<<"CHAT WITH HER!"<<endl;
    }
}
