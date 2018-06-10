#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
    static char buffer[N];
    static char *p=buffer,*end=buffer;
    if(p==end){
        if((end=buffer+fread(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    } return *p++;
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
    char buffer[4112],*ptr=buffer,*end=buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*ptr='-',++ptr,x=-x; if(!x)*ptr='0',++ptr;
        char *s=ptr,c; int t;
        while(x){t=x/10; c=x-10*t+'0'; *ptr=c,++ptr,x=t;}
        char *f=ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(ptr>end)fwrite(buffer,sizeof(char),ptr-buffer,stdout),ptr=buffer;
        *ptr=endc,++ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

int a[35555],n;
int dp[55][35555],lst[35555];

struct node{
    node *l,*r;
    int mx,tag;
    node():l(0),r(0),mx(0),tag(0){};
} *root;

void push(node *now){
    if(!now->tag)return;
    now->l->mx+=now->tag;
    now->l->tag+=now->tag;
    now->r->mx+=now->tag;
    now->r->tag+=now->tag;
    now->tag=0;
}
void pull(node *now){
    now->mx=max(now->l->mx,now->r->mx);
}

int ptr=0;
inline node *gnode(){
    return new node();
}

#define mid ((l+r)>>1)

void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=gnode(),l,mid);
    build(now->r=gnode(),mid+1,r);
}
void modify(node *now,int l,int r,int ml,int mr,int v){
    if(ml<=l&&r<=mr){
        now->tag+=v;
        now->mx+=v;
        return;
    }
    if(r<ml || mr<l)return;
    push(now);
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    pull(now);
}
int query(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 0;
    if(ql<=l&&r<=qr)return now->mx;
    push(now);
    return max(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

int main(){
    int k; rit(n,k);
    for(int i=1;i<=n;++i)rit(a[i]);
    for(int i=1;i<=k;++i){
        // cout<<i<<endl;
        build(root=gnode(),1,n);
        // cout<<"builded"<<endl;
        for(int j=1;j<=n;++j){
            modify(root,1,n,j,j,dp[i-1][j-1]);
            // c// out<<"modify "<<j<<endl;
        }
        memset(lst,0,sizeof(lst));
        for(int j=i;j<=n;++j){
            modify(root,1,n,lst[a[j]]+1,j,1);
            dp[i][j]=query(root,1,n,1,j);
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            lst[a[j]]=j;
        }
    }
    pit(dp[k][n]);
}
