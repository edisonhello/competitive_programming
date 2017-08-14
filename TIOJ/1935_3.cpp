#include<bits/stdc++.h>

using namespace std;

#define ll long long

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
#define DEBUG "jizz"
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
#define DEBUG 0
#ifdef WEA
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define FIN ;
#define FOUT ;
#endif
#endif

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename TA,typename TB,typename TC> ostream& operator<<(ostream &ostm,const priority_queue<TA,TB,TC> &inp){priority_queue<TA,TB,TC> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

inline int gtx(){
    const int N=1048576;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread(__buffer,1,N,stdin))==__buffer)return EOF;
        __p=__buffer;
    } return *__p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=getchar(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct st{bool same;ll s,t;};

int n;
vector<ll> pos;
vector<st> inf;

ll calc(ll pa,ll pb,ll ts=0){
    for(int k=0;k<n;++k){
        if(inf[k].same)ts+=inf[k].t-inf[k].s;
        else{
            if((inf[k].s<=pa && pa<=inf[k].t) || (inf[k].s<=pb && pb<=inf[k].t)){
                ts+=inf[k].t-inf[k].s+1;
            }
            else{
                ts+=min(abs(inf[k].s-pa)+abs(inf[k].t-pa),abs(inf[k].s-pb)+abs(inf[k].t-pb))+1;
            }
        }
    }
    return ts;
}

main(){
    int k;cin>>k>>n;
    inf.resize(n);
    for(int i=0;i<n;++i){
        char p,q;
        cin>>p>>inf[i].s>>q>>inf[i].t;
        if(inf[i].s>inf[i].t)swap(inf[i].s,inf[i].t);
        inf[i].same=(p==q);
        if(p==q)continue;
        pos.push_back(inf[i].s);
        pos.push_back(inf[i].t);
    }
    if(k==1){
        ll ans=0;
        if(pos.size()){
            sort(pos.begin(),pos.end());
            ll bat=(pos[pos.size()/2-1]+pos[pos.size()/2])/2;
            for(int i=0;i<n;++i){
                if(inf[i].same)ans+=abs(inf[i].s-inf[i].t);
                else ans+=abs(inf[i].s-bat)+abs(bat-inf[i].t)+1;
            }
        }
        else for(int i=0;i<n;++i)ans+=abs(inf[i].s-inf[i].t);
        cout<<ans<<endl;
    }
    else{
        if(pos.empty()){
        cout<<"meow"<<endl;
            ll ans=0;
            for(int i=0;i<n;++i)ans+=abs(inf[i].s-inf[i].t);
            cout<<ans<<endl;
        }
        else{
            cout<<"jizz"<<endl;
            sort(pos.begin(),pos.end());
            pos.resize(unique(pos.begin(),pos.end())-pos.begin());
            int jindex=1;
            bool dead=0;
            ll ans=(1ll<<58);
#ifdef WEAK
            ll rec[100][100]={0};
#endif
            for(int i=0;i<pos.size();++i){
                bool linefirst=1;
                /*{
                    int l=0,r=pos.size()-1;
                    while(r>l+2){
                        int a1=(l+l+r)/3,a2=(l+r+r)/3;
                        ll v1=calc(pos[0],pos[a1]),v2=calc(pos[0],pos[a2]); 0 limit!
                        if(v1>=v2)l=a1;
                        else r=a2;
                        PDE2(l,r);
                    } jindex=l;
                }*/
                jindex=max(jindex,i+1);
                for(int j=jindex;j<pos.size();++j){
                    ll ts=calc(pos[i],pos[j]);
                    PDE3(pos[i],pos[j],ts);
#ifdef WEAK
                    rec[i][j]=ts;
#endif
                    if(ts>ans){
                        if(linefirst)dead=1;
                        // break;
                    }
                    else{
                        // jindex=j;
                        ans=ts;
                    }
                    linefirst=0;
                }
                if(dead)break;
            }
#ifdef WEAK
            for(int i=0;i<pos.size();++i){
                for(int j=0;j<pos.size();++j)cout<<setw(4)<<rec[i][j]<<" ";
                cout<<endl;
            }
#endif
            cout<<ans<<endl;
        }
    }
}
