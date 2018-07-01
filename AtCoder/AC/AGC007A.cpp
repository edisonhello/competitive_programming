#include<bits/stdc++.h>
using namespace std;

int n,m;
string mp[9];

void JIZZ(){ cout<<"Impossible"<<endl; exit(0); }

set<pair<int,int>> st;

void dfs(int i,int j){
    if(mp[i][j]!='#')JIZZ();
    // cout<<"dfs "<<i<<" "<<j<<endl;
    st.insert(make_pair(i,j));
    if(i==n-1 && j==m-1)return;
    int go=0;
    if(i<n-1 && mp[i+1][j]=='#')++go;
    if(j<m-1 && mp[i][j+1]=='#')++go;
    if(go==2 || go==0)JIZZ();
    if(i<n-1 && mp[i+1][j]=='#')dfs(i+1,j);
    if(j<m-1 && mp[i][j+1]=='#')dfs(i,j+1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    dfs(0,0);
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(mp[i][j]=='#'){
        if(st.find(make_pair(i,j))==st.end())JIZZ();
    }
    cout<<"Possible"<<endl;
}
