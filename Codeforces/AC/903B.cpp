#include<bits/stdc++.h>
using namespace std;

int main(){
    int h1,a1,c1,h2,a2,hmax; cin>>h1>>a1>>c1>>h2>>a2; hmax=h1;
    vector<string> ans; string heal="HEAL",hit="STRIKE";
    while(h2>0){
        if(h1-a2<=0 && h2-a1>0)h1+=c1,ans.push_back(heal);
        else h2-=a1,ans.push_back(hit);
        h1-=a2;
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<endl;
}
