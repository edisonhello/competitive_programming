#include<cstdio>
#include<utility>
#include<set>
using namespace std;

#define getchar gtx
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

multiset<int> st;
int main(){
  int n;rit(n);
  for(int l,r;n;--n){
    rit(l,r);
    auto it=st.upper_bound(r);
    if(it!=st.end())st.erase(it);
    st.insert(l);
  }
  printf("%d\n",st.size());
}
