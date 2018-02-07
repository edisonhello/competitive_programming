#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pdd pair<ld,ld>
#define X first
#define Y second

int n,b,r;
vector<pdd> bp,rp;
vector<int> G[255];
bitset<255> v;
int match[255];

bool dfs(int now){
    // cout<<"dfs "<<now<<endl;
    for(int i:G[now]){
        if(v[i])continue;
        v[i]=1;
        if(match[i]==-1 || dfs(match[i])){
            match[i]=now;
            return 1;
        }
    }
    return 0;
}

ld dis(int i,int j){
    return sqrt(pow(bp[i].X-rp[j].X,2)+pow(bp[i].Y-rp[j].Y,2));
}
bool can(ld x){
    // cout<<"check x: "<<x<<endl;
    for(int i=0;i<255;++i)G[i].clear();
    for(int i=0;i<b;++i){
        for(int j=0;j<r;++j){
            if(dis(i,j)<x)G[i].push_back(j);
        }
    }
    int cnt=0;
    memset(match,-1,sizeof(match));
    for(int i=0;i<b;++i){
        if(v.reset(), dfs(i))++cnt;
    }
    return b+r-cnt>=n;
}

int main(){
    cin>>n>>b>>r;
    for(int i=0;i<b;++i){
        ld x,y; cin>>x>>y;
        bp.emplace_back(x,y);
    }
    for(int i=0;i<r;++i){
        ld x,y; cin>>x>>y;
        rp.emplace_back(x,y);
    }
    ld L=0,R=1e5;
    while(R-L>1e-8){
        ld M=(L+R)/2;
        if(can(M))L=M;
        else R=M;
    }
    cout<<fixed<<setprecision(10)<<L<<endl;
}
