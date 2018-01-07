#include<bits/stdc++.h>
using namespace std;

string mp[111];
bitset<111> u[111];

int main(){
    int n; cin>>n; 
    for(int i=0;i<n;++i)cin>>mp[i];
    int sx,sy; cin>>sx>>sy;
    queue<pair<int,int>> q; q.push({sx,sy});
    while(q.size()){
        int x=q.front().first,y=q.front().second; q.pop();
        u[x][y]=1;
        if(x>0 && !u[x-1][y] && mp[x-1][y]=='-')q.push({x-1,y});
        if(y>0 && !u[x][y-1] && mp[x][y-1]=='-')q.push({x,y-1});
        if(x<n-1 && !u[x+1][y] && mp[x+1][y]=='-')q.push({x+1,y});
        if(y<n-1 && !u[x][y+1] && mp[x][y+1]=='-')q.push({x,y+1});
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(u[i][j])cout<<"+";
            else cout<<mp[i][j];
        }
        cout<<endl;
    }
}
