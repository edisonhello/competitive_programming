#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define min(a,b) ((a)<(b)?(a):(b))

#define pll pair<long long,long long>
#define pii pair<int,int>

#ifdef WEAK
#define PDE(a) cout<<#a<<" : "<<a<<endl
#define PDE2(a,b) cout<<#a<<" : "<<a<<", "; PDE(b)
#define PDE3(a,b,c) cout<<#a<<" : "<<a<<", "; PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" : "<<a<<", "; PDE3(b,c,d)
#else
#define PDE(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#endif

int lr[1000006],ud[1000006];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<vector<string>> mp(n,vector<string>(m));
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>mp[i][j];
    for(int i=0;i<1000006;++i)lr[i]=i;
    for(int i=0;i<1000006;++i)ud[i]=i;
    int qs; cin>>qs; while(qs--){
        char cc; cin>>cc;
        if(cc=='S'){
            int q,w,e,r; cin>>q>>w>>e>>r; --q,--w,--e,--r;
            swap(mp[lr[q]][ud[w]],mp[lr[e]][ud[r]]);
        }
        else if(cc=='R'){
            int q,w; cin>>q>>w; --q;--w;
            swap(lr[q],lr[w]);
        }
        else{
            int q,w; cin>>q>>w; --q,--w;
            swap(ud[q],ud[w]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<mp[lr[i]][ud[j]]<<" ";
        } cout<<endl;
    }
}
