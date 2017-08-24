#include<iostream>
#include<vector>
#include<map>
using namespace std;

int djs[200005];
int F(int x){
    if(djs[x]==x)return x;
    else return djs[x]=F(djs[x]);
}
inline void U(int x,int y){
    x=F(x),y=F(y);
    if(x==y)return;
    djs[x]=y;
}
inline bool C(int x,int y){
    return F(x)==F(y);
}

int n,m,k,c[200005];
vector<int> djse[200005];
bool v[200005];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)cin>>c[i],djs[i]=i;
    {int a,b;while(m--){
        cin>>a>>b;
        U(a,b);
    }}
    for(int i=1;i<=n;++i){
        djse[F(i)].push_back(i);
    }
    // for(int i=1;i<=n;++i)cout<<djse[i].size()<<" ";cout<<endl;
    int ans=0;
    for(int i=1;i<=n;++i){
        if((int)djse[i].size()<2)continue;
        map<int,int> m;
        for(int j=0;j<(int)djse[i].size();++j){
            ++m[c[djse[i][j]]];
        }
        int mxs=-1;
        for(auto it:m){
            mxs=max(mxs,it.second);
        }
        // cout<<djse[i].size()<<" "<<m.begin()->second<<endl;
        ans+=(int)djse[i].size()-mxs;
        m.clear();
    }
    cout<<ans<<endl;
}
