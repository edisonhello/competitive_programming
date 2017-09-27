#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
#define rz(x) resize(x)
#define reset(x,n) (x).clear(), (x).resize(n)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define el putchar('\n')
#define spc putchar(' ')
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS(x,v) memset((x),(v),sizeof(x))
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x3f,sizeof(x))
#define MSBB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define CIO ios_base::sync_with_stdio(0);
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y2 Enyetuenwuevue
#define left Ugbemugbem
#define Osas

#ifdef WEAK
#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define DEBUG true
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define endl '\n'
#define getchar gtx
#define DEBUG false
#ifdef WEA
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define FIN ;
#define FOUT ;
#endif
#endif

struct Q{int l,r,i,bl,br,t;} q[50009];
bool operator<(const Q &a,const Q &b){
    return a.bl==b.bl?a.br==b.br?a.t<b.t:a.br<b.br:a.bl<b.bl;
}
struct R{int p,c;} r[50009];

int cnt[1000009],tot;
int ans[50009],a[50009];
int L=0,R=-1,T=0;

void movetime(int t){
    int ori=a[r[t].p];
    a[r[t].p]=r[t].c;
    r[t].c=ori;
    if(L<=r[t].p && r[t].p<=R){
        --cnt[ori]; if(cnt[ori]==0)--tot;
        ++cnt[a[r[t].p]]; if(cnt[a[r[t].p]]==1)++tot;
    }
}
void add(int v){
    ++cnt[v]; if(cnt[v]==1)++tot;
}
void ers(int v){
    --cnt[v]; if(cnt[v]==0)--tot;
}

int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i)cin>>a[i];
    int blk=(int)(ceil(pow(n,2.0/3))),chs=0;
    for(int i=0;i<m;++i){
        char c; int x,y; cin>>c>>x>>y; --y;
        if(c=='Q')q[i-chs]={x,y,i-chs,x/blk,y/blk,chs};
        else r[chs++]={x,++y};
    }
    sort(q,q+m-chs);
    for(int i=0;i<m-chs;++i){
        while(T<q[i].t)movetime(T++);
        while(T>q[i].t)movetime(--T);
        while(L>q[i].l)add(a[--L]);
        while(L<q[i].l)ers(a[L++]);
        while(R>q[i].r)ers(a[R--]);
        while(R<q[i].r)add(a[++R]);
        PDE4(T,L,R,tot);
        // if(DEBUG){for(int i=1;i<=5;++i)cout<<cnt[i]<<" ";cout<<endl;}
        // if(DEBUG){for(int i=0;i<7;++i)cout<<a[i]<<" ";cout<<endl;}
        ans[q[i].i]=tot;
    }
    for(int i=0;i<m-chs;++i){
        cout<<ans[i]<<endl;
    }
}
