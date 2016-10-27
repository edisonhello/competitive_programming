#include<bits/stdc++.h>
#define X first
#define Y second
#define PB(x) push_back(x)
#define DE cout<<"[INFO] "
using namespace std;

int n,m,xxx,yyy;
int cntDegrees[100001],minDeg,nminDeg,connectedNminDegSize;
int djs[100001],djs_size[100001];
vector<int> connected[100001];
bitset<100001> notAppered;
int cnt_sets;
bitset<100001> gone;

int F(int x){
    if(djs[x]==x) return x;
    else return djs[x]=F(djs[x]);
}
inline void U(int x,int y){
    x=F(x),y=F(y);
    if(x==y)return;
    if(djs_size[x]>djs_size[y])swap(x,y);
    djs_size[y]+=djs_size[x];
    djs[x]=y;
    return;
}
inline bool S(int x,int y){
    if(F(x)==F(y)) return 1;
    else return 0;
}

int dfs(int now){
    if(F(now)==F(nminDeg))return 1;
    // DE<<"dfsing for now="<<now<<endl;
    gone[now]=1;
    bitset<100001> tmpNotApp;
    // memset(tmpNotApp,0,sizeof(tmpNotApp));
    tmpNotApp[now]=1;
    for(int i=0;i<(int)connected[now].size();++i){
        tmpNotApp[connected[now][i]]=1;
    }
    for(int i=1;i<=n;++i){
        if(!tmpNotApp[i] && !gone[i]){
            U(now,i);
            if(dfs(i)){
                U(nminDeg,i);
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        djs[i]=i;
        djs_size[i]=1;
    }
    for(int i=0;i<m;++i){
        cin>>xxx>>yyy;
        cntDegrees[xxx]++;
        cntDegrees[yyy]++;
        connected[xxx].PB(yyy);
        connected[yyy].PB(xxx);
    }
    // finding min deg
    minDeg=cntDegrees[1];
    nminDeg=1;
    for(int i=2;i<=n;++i){
        if(cntDegrees[i]<minDeg){
            minDeg=cntDegrees[i];
            nminDeg=i;
        }
    }
    // clear it
    notAppered[nminDeg]=1;
    connectedNminDegSize=(int)connected[nminDeg].size();
    for(int i=0;i<connectedNminDegSize;i++){
        notAppered[connected[nminDeg][i]]=1;
    }
    for(int i=1;i<=n;++i){
        if(!notAppered[i]){
            U(nminDeg,i);
        }
    }
    cnt_sets=1;
    // djs
    for(int i=1;i<=n;++i){
        // DE<<"scanning "<<i<<"..."<<endl;
        if(F(i)==F(nminDeg))continue;
        gone.reset();
        if(dfs(i)){
            U(nminDeg,i);
        }
        else{
            ++cnt_sets;
            U(nminDeg,i);
        }
        // DE<<"djs:";for(int i=1;i<=n;i++)cout<<djs[i]<<" ";cout<<endl;
    }
    // djs
    cout<<cnt_sets<<'\n';
}
