#include<bits/stdc++.h>
using namespace std;

int n,m;
string mp[8];

void dfs(int x,int y,int st){
    
}

int main(){
    string s; while(getline(cin,s)){
        if(s=="#")break;
        n=m=0;
        mp[n++]=s;
        while(getline(cin,s),s.size())mp[n++]=s;
        m=mp[0].size();
        if(!dfs(0,0,0))cout<<"Another Skeleton in the Ancient Tomb!"<<endl;
    }
}
