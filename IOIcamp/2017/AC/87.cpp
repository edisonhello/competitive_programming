#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

const int lg=18;
int n,k,p[lg][100005],d[100005],in[100005],out[100005],tm;
vector<int> G[100005];


void dfs(int now,int par,int dep){
    in[now]=++tm; //cout<<now<<" ";
    p[0][now]=par;
    d[now]=dep;
    for(int i=1;i<n;++i){
        if((1<<i)>dep)break;
        p[i][now]=p[i-1][p[i-1][now]];
    }
    for(auto i:G[now]){
        if(i==par)continue;
        dfs(i,now,dep+1);
    }
    out[now]=++tm; //cout<<now<<" ";
}
int lca(int x,int y){
    // cout<<"call lca for "<<x<<" "<<y<<endl;
    if(d[x]>d[y])swap(x,y);
    for(int i=0;i<lg;++i){
        if((d[y]-d[x])&(1<<i))y=p[i][y];
        if(d[x]==d[y])break;
    }
    // cout<<x<<" "<<y<<endl;
    if(y==x)return x;
    for(int i=lg-1;i>=0;--i){
        if(p[i][x]==p[i][y])continue;
        x=p[i][x],y=p[i][y];
    }
    if(y==x)return x;
    return p[0][y];
}
bool isAnc(int x,int anc){
    // cout<<anc<<" isAnc for "<<x<<" : "<<(in[anc]<=in[x] && out[x]<=out[anc])<<endl;
    return in[anc]<=in[x] && out[x]<=out[anc];
}
bool inmid(int x,int a,int b){
    // cout<<"call inmid "<<x<<" "<<a<<" "<<b<<", rt:"<<isAnc(a,x)<<"&&"<<isAnc(x,b)<<endl;
    return isAnc(x,a)&&isAnc(b,x);
}
int main(){
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        cin>>n>>k;
        {
            for(int i=0;i<=n+1;++i){
                for(int j=0;j<lg;++j)p[j][i]=0;
                G[i].clear();d[i]=in[i]=out[i]=0;
            }
            tm=0;
        }
        {
            for(int i=1,x,y;i<n;++i){
                cin>>x>>y;--x,--y;
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }
        // cout<<"time ary: ";
        dfs(0,0,0);
        //cout<<endl;
        /*for(int i=0;i<3;++i){
            for(int j=0;j<n;++j){
                cout<<p[i][j]<<" ";
            }cout<<endl;
        }*/
        while(k--){
            int u,v,p,q;cin>>u>>v>>p>>q;--u,--v,--p,--q;
            int uvlca=lca(u,v);// cout<<"uvlca: "<<uvlca<<" ,";
            int pqlca=lca(p,q);// cout<<"pqlca: "<<pqlca<<"\n";
            if(inmid(uvlca,pqlca,p) || inmid(uvlca,pqlca,q) ||
               inmid(pqlca,uvlca,u) || inmid(pqlca,uvlca,v)){
                cout<<"tsan"<<endl;
            }
            else cout<<"hao"<<endl;
        }
    }
}
