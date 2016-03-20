#include<bits/stdc++.h>
using namespace std;
int main(){
    int  n;cin>>n;
    string a;cin>>a;
    int cnt=0;int i,j;
    for(i=0;i<a.length();i=j){
        for(j=i+1;a[i]==a[j];j++){
            cnt++;
        }
    }cout<<cnt<<endl;
}
