#include<bits/stdc++.h>
using namespace std;

struct pos{int x,y,z;};
string mp[33][33];
bitset<33> v[33][33];
int d[33][33][33];

int dx[]={0,0,1,-1,0,0};
int dy[]={1,-1,0,0,0,0};
int dz[]={0,0,0,0,1,-1};

int main(){
    int z,x,y; while(cin>>z>>x>>y,z){
        for(int i=0;i<33;++i)for(int j=0;j<33;++j)v[i][j].reset();
        for(int i=0;i<z;++i)for(int ii=0;ii<x;++ii)cin>>mp[i][ii];
        int sx,sy,sz,tx,ty,tz;
        for(int k=0;k<z;++k){
            for(int i=0;i<x;++i){
                for(int j=0;j<y;++j){
                    if(mp[k][i][j]=='S')tie(sx,sy,sz)={i,j,k};
                    if(mp[k][i][j]=='E')tie(tx,ty,tz)={i,j,k};
                }
            }
        }
        memset(d,-1,sizeof(d));
        queue<pos> q; q.push({sx,sy,sz}); v[sz][sx][sy]=1; d[sz][sx][sy]=0;
        while(q.size()){
            pos now=q.front(); q.pop();
            // cout<<now.x<<" "<<now.y<<" "<<now.z<<endl;
            for(int dr=0;dr<6;++dr){
                int nx=now.x+dx[dr];
                int ny=now.y+dy[dr];
                int nz=now.z+dz[dr];
                if(nz>=0 && nx>=0 && ny>=0 && nz<z && nx<x && ny<y && mp[nz][nx][ny]!='#' && !v[nz][nx][ny]){
                    v[nz][nx][ny]=1;
                    d[nz][nx][ny]=d[now.z][now.x][now.y]+1;
                    q.push({nx,ny,nz});
                }
            }
        }
        if(d[tz][tx][ty]==-1)cout<<"Trapped!"<<endl;
        else cout<<"Escaped in "<<d[tz][tx][ty]<<" minute(s)."<<endl;
    }
}
