#include<bits/stdc++.h>
#define X first
#define Y second
#define PB(x) push_back(x)
#define DE cout<<"[INFO] "
using namespace std;

int n,m,xxx,yyy;
int cntDegrees[100005],minDeg,nminDeg;
int djs[100005],djs_size[100005];
vector<int> connected[100005];
bitset<100005> notAppered;
int cnt_sets;
bitset<100005> gone;

int F(int x){
    if(djs[x]==0) return x;
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
    // DE<<"dfsing for now="<<now<<endl;
    bitset<100005> tmpNotApp;
    // memset(tmpNotApp,0,sizeof(tmpNotApp));
    tmpNotApp[now]=1;
    gone[now]=1;
    for(int i=0;i<(int)connected[now].size();i++){
        tmpNotApp[connected[now][i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(!tmpNotApp[i] && !gone[i]){
            U(now,i);
            int DFSResult = dfs(i);
            if(DFSResult == -102928){
                U(nminDeg,i);
                return -102928;
            }
        }
    }
    return 39;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // inputting
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>xxx>>yyy;
        cntDegrees[xxx]++;
        cntDegrees[yyy]++;
        connected[xxx].PB(yyy);
        connected[yyy].PB(xxx);
    }
    // inputting
    // finding min deg
    minDeg=cntDegrees[1];
    nminDeg=1;
    for(int i=2;i<=n;i++){
        if(cntDegrees[i]<minDeg){
            minDeg=cntDegrees[i];
            nminDeg=i;
        }
    }
    memset(djs_size,1,sizeof(djs_size));
    notAppered[nminDeg]=1;
    for(int i=0;i<(int)connected[nminDeg].size();i++){
        notAppered[connected[nminDeg][i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(!notAppered[i]){
            U(nminDeg,i);
        }
    }
    cnt_sets=1;
    // DE<<"get nminDeg="<<nminDeg<<"\n";
    // DE<<"djs:";for(int i=1;i<=n;i++)cout<<djs[i]<<" ";cout<<endl;
    // finding min deg
    // djs
    for(int i=1;i<=n;i++){
        // DE<<"scanning "<<i<<"..."<<endl;
        if(F(i)==F(nminDeg))continue;
        int DFSResult = dfs(i);
        if(DFSResult == -102928){
            U(nminDeg,i);
        }
        else if(DFSResult == 39){
            cnt_sets++;
            U(nminDeg,i);
        }
        // DE<<"djs:";for(int i=1;i<=n;i++)cout<<djs[i]<<" ";cout<<endl;
    }
    // djs
    cout<<cnt_sets<<endl;
}
