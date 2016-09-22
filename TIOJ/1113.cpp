#include<bits/stdc++.h>
using namespace std;
string s;
bool took[8];
vector<string> ans;
void t(string now){
    if(now.length()==s.length()){
        ans.push_back(now);
        return;
    }
    for(int i=0;i<s.length();i++){
        if(!took[i]){
            took[i]=1;
            t(now+s[i]);
            took[i]=0;
        }
    }
    return;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>s){
        sort(s.begin(),s.end());
        memset(took,0,sizeof(took));
        ans.clear();
        t("");
        for(auto i:ans)cout<<i<<endl;
        cout<<endl;
    }
}
