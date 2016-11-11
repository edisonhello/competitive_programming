#include<iostream>
#include<queue>
using namespace std;
bool g[1005][1005],ct[1005][1005];
int m,n,sx,sy,ex,ey;
struct s{int x,y,d;};
queue<s> q;
int main(){
    cin>>m>>n;
    for(int i=0,tx,ty;i<n;++i){
        cin>>tx>>ty;
        ct[tx][ty]=1;
    }
    for(int i=0;i<=m+1;++i){
        ct[0][i]=ct[m+1][i]=ct[i][0]=ct[i][m+1]=1;
    }
    cin>>sx>>sy>>ex>>ey;
    q.push({sx,sy,0});
    g[sx][sy]=1;
    while(q.size()){
        s f=q.front();q.pop();
        if(f.x==ex && f.y==ey){cout<<f.d<<endl;return 0;}
        if(!g[f.x+1][f.y] && !ct[f.x+1][f.y]){q.push({f.x+1,f.y,f.d+1});g[f.x+1][f.y]=1;}
        if(!g[f.x-1][f.y] && !ct[f.x-1][f.y]){q.push({f.x-1,f.y,f.d+1});g[f.x-1][f.y]=1;}
        if(!g[f.x][f.y+1] && !ct[f.x][f.y+1]){q.push({f.x,f.y+1,f.d+1});g[f.x][f.y+1]=1;}
        if(!g[f.x][f.y-1] && !ct[f.x][f.y-1]){q.push({f.x,f.y-1,f.d+1});g[f.x][f.y-1]=1;}
    }
    cout<<-1<<endl;
}
