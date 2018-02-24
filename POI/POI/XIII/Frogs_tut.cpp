#include<bits/stdc++.h>
using namespace std;
#define ld long double


bitset<1004> v[1004];
stack<pair<ld,pair<int,int>>> stk;
pair<int,int> djs[1004][1004];

struct info{
    int x,y;
    int sx,sy;
    int getdis(){
        return (sx-x)*(sx-x)+(sy-y)*(sy-y);
    }
};
bool operator<(const info &a,const info &b){return a->getdis()<b->getdis();}
bool operator>(const info &a,const info &b){return a->getdis()>b->getdis();}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y; cin>>x>>y;
    int sx,sy,ex,ey; cin>>sx>>sy>>ex>>ey;
    int n; cin>>n;
    priority_queue<info,vector<info>,greater<info>> q;
    while(n--){
        int x,y; cin>>x>>y;
        q.push({x,y,x,y});
        v[x][y]=1;
    }
    while(q.size()){
        while(q.size() && v[q.top().x][q.top().y])q.pop();
        if(q.empty())break;
        int nx=q.top().x,ny=q.top().y;
        v[nx][ny]=1;
        stk.push({q.top()->getdis(),make_pair(nx,ny)});
        if(nx>1 && !v[nx-1][ny])q.push({nx-1,ny,q.top().sx,q.top().sy});
        if(nx<x && !v[nx+1][ny])q.push({nx+1,ny,q.top().sx,q.top().sy});
        if(ny>1 && !v[nx][ny-1])q.push({nx,ny-1,q.top().sx,q.top().sy});
        if(ny<y && !v[nx][ny+1])q.push({nx,ny+1,q.top().sx,q.top().sy});
    }
    for(int i=1;i<=x;++i){
        for(int j=1;j<=y;++j){
            djs[i][j]={i,j};
        }
    }
    ld ans=1e20;
    while(0==0){
        

        if(F(sx,sy)==F(ex,ey))
    }
}
