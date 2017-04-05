#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
// #include<unordered_map>
// #include<unordered_set>
#include<bitset>
#include<vector>
#include<utility>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
#define rz(x) resize(x)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define endl '\n'
#define el putchar('\n')
#define spc putchar(' ')
#define mid ((l+r)>>1)
#define xm ((x1+x2)/2)
#define ym ((y1+y2)/2)
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define CIO ios_base::sync_with_stdio(0);

int G[111][111],n;
bool v[111];

void dfs(int now,int ctg){
    // PDE2(now,ctg);
    v[now]=1;
    for(int i=1;i<=n;++i){
        if(i==ctg)continue;
        if(G[now][i] && !v[i])dfs(i,ctg);
    }
}

int main(){
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    while(cin>>n,n){ // PDE1(n);
        memset(G,0,sizeof(G));
        string s;// getline(cin,s);
        while(getline(cin,s) && s[0]!='0'){
            SS ss(s);
            int st,ed;ss>>st;
            while(ss>>ed)G[st][ed]=G[ed][st]=1;
        }
        // LOG("finish output\n");
        int ans=0;
        for(int i=1;i<=n;++i){
            int blks=0;
            memset(v,0,sizeof(v));
            for(int j=1;j<=n;++j){
                if(i==j)continue;
                if(v[j])continue;
                dfs(j,i); ++blks;
                // LOG("blks++\n");
            }
            if(blks>1)++ans;
        }
        cout<<ans<<endl;
    }
}
