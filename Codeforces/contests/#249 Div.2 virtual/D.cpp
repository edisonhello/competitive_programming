// #pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("Ofast")
// #pragma GCC diagnostic ignored "-W"

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
#include<bitset>
#include<vector>
#include<utility>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)

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
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__,5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define PDE1(a) cout<<#a<<" = "<<(a)<<endl
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#define PDE(...) macro_dispatcher(PDE, __VA_ARGS__)(__VA_ARGS__)
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
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

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const multiset<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename TA,typename TB,typename TC> ostream& operator<<(ostream &ostm,const priority_queue<TA,TB,TC> &inp){priority_queue<TA,TB,TC> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}
// ostream& operator<<(ostream &ostm,const __int128 &val){if(!val){ostm<<"0"; return ostm;} bool mns=0; __int128 cpy=(val<0?mns=1,-val:val); stack<char> st; while(cpy)st.push(cpy%10+'0'),cpy/=10; if(mns)st.push('-'); while(st.size())ostm<<st.top(),st.pop(); return ostm;}
#endif

void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

string mp[444];

string getnew(){
    string rt;
    for(int i=0;i<400;++i)rt+="0";
    return rt;
}

bool diaisok[2][444][444][444];

int main(){
    CPPinput;
    short n,m; cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    // short n=400,m=400;
    // for(int i=0;i<n;++i)mp[i]=getnew();
    
    int ans=0;

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            diaisok[0][i][j][0]=(mp[i][j]=='0');
            for(int len=1;;++len){
                if(i+len>=n || j+len>=m)break;
                diaisok[0][i][j][len]=diaisok[0][i][j][len-1]&(mp[i+len][j+len]=='0');
                if(!diaisok[0][i][j][len])break;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            diaisok[1][i][j][0]=(mp[i][j]=='0');
            PDE(i,j,diaisok[1][i][j][0]);
            for(int len=1;;++len){
                if(i-len<0 || j+len>=m)break;
                diaisok[1][i][j][len]=diaisok[1][i][j][len-1]&(mp[i-len][j+len]=='0');
                PDE(len,mp[i-len][j+len]=='0',diaisok[1][i][j][len-1],diaisok[1][i][j][len]);
                if(!diaisok[1][i][j][len])break;
            }
        }
    }

    PDE(1);
    for(register short i=0,j,len;i<n;++i){
        for(j=0;j<m;++j){
            if(mp[i][j]=='1')continue;
            for(len=1;;++len){
                if(i+len>=n || j+len>=m)break;
                if(mp[i+len][j]=='1' || mp[i][j+len]=='1')break;
                bool ok=diaisok[1][i+len][j][len];
                /* for(int ofs=1;ofs<len;++ofs){
                    if(mp[i+len-ofs][j+ofs]=='1'){ok=0; break;}
                } */
                PDE(diaisok[1][i+len][j][len]);
                if(ok){
                    ++ans;
                    PDE(i,j,len);
                }
            }
        }
    }
    PDE(2);
    for(register short i=0,j,len;i<n;++i){
        for(j=0;j<m;++j){
            if(mp[i][j]=='1')continue;
            for(len=1;;++len){
                if(i+len>=n || j-len<0)break;
                if(mp[i+len][j]=='1' || mp[i][j-len]=='1')break;
                bool ok=diaisok[0][i][j-len][len];
                /* for(int ofs=1;ofs<len;++ofs){
                    if(mp[i+len-ofs][j-ofs]=='1'){ok=0; break;}
                } */
                if(ok){
                    ++ans;
                    PDE(i,j,len);
                }
            }
        }
    }
    PDE(3);
    for(register short i=0,j,len;i<n;++i){
        for(j=0;j<m;++j){
            if(mp[i][j]=='1')continue;
            for(len=1;;++len){
                if(i-len<0 || j-len<0)break;
                if(mp[i-len][j]=='1' || mp[i][j-len]=='1')break;
                bool ok=diaisok[1][i][j-len][len];
                /* for(int ofs=1;ofs<len;++ofs){
                    if(mp[i-len+ofs][j-ofs]=='1'){ok=0; break;}
                } */
                if(ok){
                    PDE(i,j,len);
                    ++ans;
                }
            }
        }
    }
    PDE(4);
    for(register short i=0,j,len;i<n;++i){
        for(j=0;j<m;++j){
            if(mp[i][j]=='1')continue;
            for(len=1;;++len){
                if(i-len<0 || j+len>=m)break;
                if(mp[i-len][j]=='1' || mp[i][j+len]=='1')break;
                bool ok=diaisok[0][i-len][j][len];
                /* for(int ofs=1;ofs<len;++ofs){
                    if(mp[i-len+ofs][j+ofs]=='1'){ok=0; break;}
                } */
                if(ok){
                    ++ans;
                    PDE(i,j,len);

                }
            }
        }
    }
    for(register short i=0,j,len;i<n;++i){
        for(j=0;j<m;++j){
            if(mp[i][j]=='1')continue;
            for(len=1;;++len){
                if(i+len*2>=n || j+len>=m)break;
                if(mp[i+len*2][j]=='1' || mp[i+len*2-1][j]=='1' || mp[i+len][j+len]=='1')break;
                bool ok=diaisok[1][i+len*2][j][len];
                /* for(int ofs=1;ofs<len;++ofs){
                    if(mp[i+len*2-ofs][j+ofs]=='1'){ok=0; break;}
                } */
                if(ok)++ans;
            }
        }
    }
    for(register short i=0,j,len;i<n;++i){
        for(j=0;j<m;++j){
            if(mp[i][j]=='1')continue;
            for(len=1;;++len){
                if(i+len*2>=n || j-len<0)break;
                if(mp[i+len*2][j]=='1' || mp[i+len*2-1][j]=='1' || mp[i+len][j-len]=='1')break;
                bool ok=diaisok[0][i+len][j-len][len];
                /* for(int ofs=1;ofs<len;++ofs){
                    if(mp[i+len*2-ofs][j-ofs]=='1'){ok=0; break;}
                } */
                if(ok)++ans;
            }
        }
    }
    for(register short i=0,j,len;i<n;++i){
        for(j=0;j<m;++j){
            if(mp[i][j]=='1')continue;
            for(len=1;;++len){
                if(i+len>=n || j+len*2>=m)break;
                if(mp[i][j+len*2]=='1' || mp[i][j+len*2-1]=='1' || mp[i+len][j+len]=='1')break;
                bool ok=diaisok[1][i+len][j+len][len];
                /* for(int ofs=1;ofs<len;++ofs){
                    if(mp[i+ofs][j+len*2-ofs]=='1'){ok=0; break;}
                } */
                if(ok)++ans;
            }
        }
    }
    for(register short i=0,j,len;i<n;++i){
        for(j=0;j<m;++j){
            if(mp[i][j]=='1')continue;
            for(len=1;;++len){
                if(i-len<0 || j+len*2>=m)break;
                if(mp[i][j+len*2]=='1' || mp[i][j+len*2-1]=='1' || mp[i-len][j+len]=='1')break;
                bool ok=diaisok[0][i-len][j+len][len];
                /* for(int ofs=1;ofs<len;++ofs){
                    if(mp[i-ofs][j+len*2-ofs]=='1'){ok=0; break;}
                } */
                if(ok)++ans;
            }
        }
    }
    cout<<ans<<endl;
}
