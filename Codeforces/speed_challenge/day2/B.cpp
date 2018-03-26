#include<bits/stdc++.h>
using namespace std;

pair<char,char> ans[44];

int main(){
    string a,b; cin>>a>>b;
    if(a[0]>b[0]){
        for(int i=0;i<a[0]-b[0];++i)ans[i].first='L';
    }
    else{
        for(int i=0;i<b[0]-a[0];++i)ans[i].first='R';
    }
    if(a[1]>b[1]){
        for(int i=0;i<a[1]-b[1];++i)ans[i].second='D';
    }
    else{
        for(int i=0;i<b[1]-a[1];++i)ans[i].second='U';
    }
    for(int i=0;;++i){
        if(ans[i].first==0 && ans[i].second==0){
            cout<<i<<endl;
            break;
        }
    }
    for(int i=0;;++i){
        if(ans[i].first==0 && ans[i].second==0){
            exit(0);
        }
        if(ans[i].first)cout<<ans[i].first;
        if(ans[i].second)cout<<ans[i].second;
        cout<<endl;
    }
}
