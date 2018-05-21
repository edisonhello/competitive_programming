#pragma GCC optimize("no-stack-protector")
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

struct seg{
    int l,r,i;
} a[200005];

int bit[400005];

inline void padd(int x,int v){
    for(;x<400005;x+=x&-x)bit[x]+=v;
}
inline int pqry(int x,int v=0){
    for(;x;x-=x&-x)v+=bit[x];
    return v;
}

int far[19][400005],num[400005];

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#define fread fread_unlocked
#define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
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
    char _buffer[4112],*_ptr=_buffer,*_end=_buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*_ptr='-',++_ptr,x=-x; if(!x)*_ptr='0',++_ptr;
        char *s=_ptr,c; int t;
        while(x){t=x/10; c=x-10*t+'0'; *_ptr=c,++_ptr,x=t;}
        char *f=_ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(_ptr>_end)fwrite(_buffer,sizeof(char),_ptr-_buffer,stdout),_ptr=_buffer;
        *_ptr=endc,++_ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(_buffer,sizeof(char),_ptr-_buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

int top=1;
int get(int L,int R){
    // cout<<"getting "<<L<<" to "<<R<<endl;
    int rt=0,ptr=top-1;
    while(R>=L){
        // cout<<L<<" "<<R<<" "<<ptr<<" "<<far[ptr][L]<<endl;
        while(ptr>=0 && far[ptr][L]>R)--ptr;
        if(ptr>=0 && far[ptr][L]<=R){
            L=far[ptr][L]+1;
            rt+=1<<ptr;
        }
        else break;
    }
    // cout<<"rt: "<<rt<<endl;
    return rt;
}

int main(){
    int n; rit(n);
    seg *aa=a+1;
    for(int i=1;i<=n;++i,++aa)rit(aa->l,aa->r),aa->i=i;
    /* if(0){
        cout<<n<<endl;
        for(int i=1;i<=n;++i)cout<<a[i].l<<" "<<a[i].r<<endl;
    } */
    aa=a+1;
    for(int i=1;i<=n;++i,++aa)num[(i<<1)-2]=aa->l,num[(i<<1)-1]=aa->r;
    sort(num,num+(n<<1));
    int nn=unique(num,num+(n<<1))-num;
    aa=a+1;
    for(int i=1;i<=n;++i,++aa)aa->l=upper_bound(num,num+nn,aa->l)-num;
    aa=a+1;
    for(int i=1;i<=n;++i,++aa)aa->r=upper_bound(num,num+nn,aa->r)-num;
    // for(int i=1;i<=n;++i)cout<<a[i].l<<" - "<<a[i].r<<endl;
    memset(far[0],0x3f,400005<<2);
    aa=a+1;
    for(int i=1;i<=n;++i,++aa)far[0][aa->l]=min(far[0][aa->l],aa->r);
    for(int i=nn+3;i>=0;--i)far[0][i]=min(far[0][i],far[0][i+1]);
    // for(int i=0;i<=21;++i)cout<<"far[0]["<<i<<"]: "<<far[0][i]<<endl;
    for(;(1<<top)<n;++top){
        if(far[top-1][0]==0x3f3f3f3f)break;
        memset(far[top],0x3f,400005<<2);
        for(int j=0;;++j){
            if(far[top-1][j]==0x3f3f3f3f)break;
            far[top][j]=far[top-1][far[top-1][j]+1];
        }
        // if(i<4)for(int j=0;j<=18;++j)cout<<"far["<<i<<"]["<<j<<"]: "<<far[i][j]<<endl;
    }
    set<int> pos;
    pos.insert(0); pos.insert(nn+1);
    pit(get(1,nn));
    aa=a+1;
    for(int i=1,L,R;i<=n;++i,++aa){
        // cout<<"i: "<<i<<" "<<a[i].l<<" "<<a[i].r<<" "<<qry(a[i].l)<<endl;
        if(pqry(aa->l))continue;
        auto it=pos.upper_bound(aa->r);
        if((*--it)>=aa->l)continue;
        L=*it+1; ++it; R=*it-1;
        if(get(L,aa->l-1)+get(aa->r+1,R)!=get(L,R)-1)continue;
        pit.write(i,' ');
        pos.insert(aa->l); pos.insert(aa->r);
        padd(aa->l,1); padd(aa->r+1,-1);
    }
}
