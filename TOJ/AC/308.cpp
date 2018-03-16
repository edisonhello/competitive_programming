#include<bits/stdc++.h>
using namespace std;

int n;
bitset<123> u;
vector<int> ans;

void dfs(string &s,int ptr){
    if(ptr>=s.size()){
        for(int i:ans)cout<<i<<" \n"[i==ans.back()];
        exit(0);
    }
    int x=(s[ptr]-'0');
    if(x<=n && !u[x]){
        u[x]=1;
        ans.push_back(x);
        dfs(s,ptr+1);
        u[x]=0;
        ans.pop_back();
    }
    if(ptr+1<s.size()){
        int x=(s[ptr]-'0')*10+s[ptr+1]-'0';
        if(x<=n && !u[x]){
            u[x]=1;
            ans.push_back(x);
            dfs(s,ptr+2);
            u[x]=0;
            ans.pop_back();
        }
    }
}

int main(){
    string s; cin>>s;
    if(s.size()<10u)n=s.size();
    else n=(s.size()-9)/2+9;
    dfs(s,0);
}
