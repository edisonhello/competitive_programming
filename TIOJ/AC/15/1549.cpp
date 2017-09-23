#include<cstdio>
#include<stack>
#include<algorithm>

#define ll long long
#define ld long double
#define X first
#define Y second
#define rz(x) resize(x)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
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
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define exp expexpexpexp
#define expl explexplexpl

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

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
#define DEBUG 1
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define getchar gtx
#define FIN ;
#define FOUT ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))
using namespace std;


int v[2000006];
int l[2000006];
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&v[i]);
        // inf[i]=i;
        l[i]=99999999;
    }
    ll ans=0;
    stack<int> st;
    for(int i=1;i<=n;++i){
        while(st.size() && v[st.top()]>v[i]){
            l[st.top()]=-v[i]+v[st.top()];
            st.pop();
        }
        st.push(i);
    }
    while(st.size())st.pop();
    for(int i=n;i>=1;--i){
        while(st.size() && v[st.top()]>v[i]){
            l[st.top()]=min(l[st.top()],-v[i]+v[st.top()]);
            st.pop();
        }
        st.push(i);
    }
    for(int i=1;i<=n;++i){
        if(l[i]==99999999)continue;
        ans+=(ll)l[i]*(ll)l[i];
        PDE2(i,l[i]);
    }
    /*
    std::sort(inf+1,inf+1+n,[](const int &a,const int &b){return oriv[a]<oriv[b];});
    ll ans=0;
    for(int i=1,lv,rv;i<=n;++i){
        if(st.empty())st.insert(inf[i]);
        else{
            auto it=st.lower_bound(inf[i]);
            lv=-1,rv=-1;
            if(it!=st.end())rv=oriv[*it];
            if((it--)!=st.begin())lv=oriv[*it];
            ans+=((ll)std::max(lv,rv)-(ll)oriv[inf[i]])*((ll)std::max(lv,rv)-(ll)oriv[inf[i]]);
            st.insert(inf[i]);
        }
    }*/
    printf("%lld\n",ans);
}
