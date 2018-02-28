#include<bits/stdc++.h>
using namespace std;

int a,b;
int sx[1009],sy[1009];
bitset<1009> vip[1009];
map<int,int> id;
int dx[]={1,1,1,0,-1,-1,-1,0};
int dy[]={1,0,-1,-1,-1,0,1,1};
vector<int> G[4009];
int pcnt=0;

bool inside(int x,int y){
    return x>=1&&x<=a&&y>=1&&y<=b;
}

int dfs(int ptr,bitset<409> &v){
    if(clock()/(1.0*CLOCKS_PER_SEC)>0.48)return 0;
    int mx=0;
    for(int i=ptr;i<pcnt;++i){
        if(clock()/(1.0*CLOCKS_PER_SEC)>0.48)return mx;
        if(!v[i]){
            v[i]=1;
            vector<int> chg;
            for(int &ii:G[i]){
                chg.push_back(ii);
                v[ii]=1;
            }
            mx=max(mx,dfs(i+1,v)+1);
            for(int &ii:chg)v[ii]=0;
            v[i]=0;
        }
    }
    return mx;
}


int gid(int x,int y){
    int hsh=x*10000+y;
    auto it=id.find(hsh);
    if(it==id.end()){
        id[hsh]=pcnt++;
        return pcnt-1;
    }
    return it->second;
}
int main(){
    clock();
    // freopen("in","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int c; cin>>a>>b>>c;
    for(int i=0;i<c;++i){
        cin>>sx[i]>>sy[i];
        if(sx[i]>1)vip[sx[i]-1][sy[i]]=1;
        if(sx[i]<a)vip[sx[i]+1][sy[i]]=1;
        if(sy[i]>1)vip[sx[i]][sy[i]-1]=1;
        if(sy[i]<b)vip[sx[i]][sy[i]+1]=1;
    }
    for(int i=0;i<c;++i){
        vip[sx[i]][sx[i]]=0;
    }
    for(int i=1;i<=a;++i){
        for(int j=1;j<=b;++j){
            if(vip[i][j]){
                int aid=gid(i,j);
                for(int k=0;k<8;++k){
                    if(inside(i+dx[k],j+dy[k]) && vip[i+dx[k]][j+dy[k]]){
                        int bid=gid(i+dx[k],j+dy[k]);
                        G[aid].push_back(bid);
                        G[bid].push_back(aid);
                    }
                }
            }
        }
    }
    bitset<409> v;
    cout<<dfs(0,v)<<endl;
}
