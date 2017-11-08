#include<bits/stdc++.h>
using namespace std;

void getmin(int m,int s){
    string ans;
    ans.push_back('1');
    for(int i=1;i<m;++i)ans.push_back('0'); --s;
    for(int i=ans.size()-1;i>=0;){
        if(!s)break;
        ++ans[i]; --s;
        if(ans[i]=='9')--i;
    }
    cout<<ans<<" ";
}
void getmax(int m,int s){
    string ans;
    ans.push_back('1');
    for(int i=1;i<m;++i)ans.push_back('0'); --s;
    for(int i=0;i<ans.size();){
        if(!s)break;
        ++ans[i]; --s;
        if(ans[i]=='9')++i;
    }
    cout<<ans<<endl;
}

int main(){
    int m,s; cin>>m>>s;
    if(m==1 && s==0)return cout<<"0 0"<<endl,0;
    if(s==0 || s>9*m)return cout<<"-1 -1"<<endl,0;
    getmin(m,s); getmax(m,s);
}
