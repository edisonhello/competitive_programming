#include<bits/stdc++.h>
using namespace std;

// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx(){
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
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char _buffer[1048576],*_ptr=_buffer,*_end=_buffer+1048576;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*_ptr='-',++_ptr,x=-x; if(!x)*_ptr='0',++_ptr;
        char *s=_ptr,c; int t;
        while(x){t=x/10; c=x-10*t+'0'; *_ptr=c,++_ptr,x=t;}
        char *f=_ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(_ptr>_end)fwrite(_buffer,sizeof(char),_ptr-_buffer,stdout),_ptr=_buffer;
        *_ptr=endc,++_ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n');}
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(_buffer,sizeof(char),_ptr-_buffer,stdout); }
} pit;

set<int> xs[100005],ys[100005];

int main(){
    int n; rit(n);
    for(int i=0,x,y;i<n;++i){
        rit(x,y);
        xs[y].insert(x);
        ys[x].insert(y);
    }
    int ans=0;
    for(int x=0;x<=100000;++x){
        auto it=ys[x].begin();
        while(it!=ys[x].end()){
            int y=*it;
            int count_up=ys[x].size();
            int count_rg=xs[y].size();
            if(count_up<count_rg){
                for(auto iit=next(it);iit!=ys[x].end();++iit){
                    int dis=*iit-y;
                    if(ys[x+dis].find(y)!=ys[x+dis].end() && ys[x+dis].find(y+dis)!=ys[x+dis].end()){
                        ++ans;
                    }
                }
            }
            else{
                for(auto iit=next(xs[y].begin());iit!=xs[y].end();++iit){
                    int dis=*iit-x;
                    if(xs[y+dis].find(x)!=xs[y+dis].end() && xs[y+dis].find(x+dis)!=xs[y+dis].end()){
                        ++ans;
                    }
                }
            }
            it=ys[x].erase(it);
            xs[y].erase(xs[y].begin());
        }
    }
    pit(ans);
}
