#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n,m; 
pair<int,int> pos[100005];
int conto[100005][4]; // [right, down ,left, up], wall number
pair<int,int> wall[100005];

namespace small{ 

bitset<555> blockr[555],blockd[555];
int color[555][555];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
set<int> G[255555];
int dep[255555];

const int CMX=505;

void bfs(int x,int y,int co){
    queue<pair<int,int>> q; q.emplace(x,y);
    color[x][y]=co;
    while(q.size()){
        auto p=q.front(); q.pop();
        for(int d=0,nx,ny;d<4;++d){
            nx=p.X+dx[d];
            ny=p.Y+dy[d];
            if(nx<0 || ny<0 || nx>CMX || ny>CMX)continue;
            if(dx[d]==1 && blockd[p.X][p.Y])continue;
            if(dx[d]==-1&& blockd[nx][ny])continue;
            if(dy[d]==1 && blockr[p.X][p.Y])continue;
            if(dy[d]==-1&& blockr[nx][ny])continue;
            if(color[nx][ny])continue;
            q.emplace(nx,ny);
            color[nx][ny]=co;
        }
    }
}

void bfs2(int now){
    queue<int> q; q.push(now); dep[now]=1;
    while(q.size()){
        int now=q.front(); q.pop();
        for(int i:G[now]){
            if(dep[i])continue;
            dep[i]=dep[now]+1;
            q.push(i);
        }
    }
}

void solve(){
    for(int i=1;i<=m;++i){
        if(pos[wall[i].X].X!=pos[wall[i].Y].X){
            for(int x=pos[wall[i].X].X;x<pos[wall[i].Y].X;++x){
                blockr[x][pos[wall[i].X].Y-1]=1;
            }
        }
        else{
            for(int y=pos[wall[i].X].Y;y<pos[wall[i].Y].Y;++y){
                blockd[pos[wall[i].X].X-1][y]=1;
            }
        }
    }
    int co=0;
    for(int i=0;i<=CMX+2;++i){
        for(int j=0;j<=CMX+2;++j){
            if(!color[i][j]){
                bfs(i,j,++co);
            }
        }
    }
    /* for(int i=0;i<=CMX;++i){
        for(int j=0;j<=CMX;++j){
            cout<<color[i][j]<<" ";
        }
        cout<<endl;
    } */
    for(int i=1;i<=m;++i){
        if(pos[wall[i].X].X!=pos[wall[i].Y].X){
            for(int x=pos[wall[i].X].X;x<pos[wall[i].Y].X;++x){
                // cout<<color[x][pos[wall[i].X].Y-1]<<" and "<<color[x][pos[wall[i].X].Y]<<endl;
                G[color[x][pos[wall[i].X].Y-1]].insert(color[x][pos[wall[i].X].Y]);
                G[color[x][pos[wall[i].X].Y]].insert(color[x][pos[wall[i].X].Y-1]);
            }
        }
        else{
            for(int y=pos[wall[i].X].Y;y<pos[wall[i].Y].Y;++y){
                G[color[pos[wall[i].X].X-1][y]].insert(color[pos[wall[i].X].X][y]);
                G[color[pos[wall[i].X].X][y]].insert(color[pos[wall[i].X].X+1][y]);
            }
        }
    }
    bfs2(1);
    // for(int i=1;i<=m;++i)cout<<"d of "<<i<<" : "<<dep[i]<<endl;
    set<int> stand;
    for(int i=1;i<=m;++i)stand.insert(i);
    for(int i=1;i<=m;++i){
        if(pos[wall[i].X].X!=pos[wall[i].Y].X){
            for(int x=pos[wall[i].X].X;x<pos[wall[i].Y].X;++x){
                if(dep[color[x][pos[wall[i].X].Y-1]]!=dep[color[x][pos[wall[i].X].Y]]){
                    stand.erase(i);
                }
            }
        }
        else{
            for(int y=pos[wall[i].X].Y;y<pos[wall[i].Y].Y;++y){
                if(dep[color[pos[wall[i].X].X-1][y]]!=dep[color[pos[wall[i].X].X][y]]){
                    stand.erase(i);
                }
            }
        }
    }
    cout<<stand.size()<<'\n';
    for(int i:stand)cout<<i<<'\n';
}}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>pos[i].first>>pos[i].second;
    }
    cin>>m;
    for(int i=1,u,v;i<=m;++i){
        cin>>u>>v;
        if(pos[u].X==pos[v].X){
            if(pos[v].Y<pos[u].Y)swap(u,v);
            conto[u][0]=i;
            conto[v][2]=i;
        }
        else{
            if(pos[v].X<pos[u].X)swap(u,v);
            conto[u][1]=i;
            conto[v][3]=i;
        }
        wall[i].first=u, wall[i].second=v;
    }
    small::solve();
}
// in virtual 30 pts
