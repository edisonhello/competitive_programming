#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2")

#include<bits/stdc++.h>
using namespace std;

#define point vector<int>

int k;

struct node{
    node *l,*r;
    vector<int> p;
    node():l(0),r(0){}
} *root;

point p[200005];

void merge(vector<int> &r,const vector<int> &a,const vector<int> &b){
    for(int z=0;z<32;++z){
        r[z]=(p[a[z]][z+5]>=p[b[z]][z+5])?a[z]:b[z];
    }
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        now->p.resize(32,l);
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->p.resize(32);
    merge(now->p,now->l->p,now->r->p);
}

void modify(node *now,int l,int r,int x){
    if(l==r){
        for(int i=0;i<32;++i)now->p[i]=l;
        return;
    }
    if(x<=mid)modify(now->l,l,mid,x);
    else modify(now->r,mid+1,r,x);
    merge(now->p,now->l->p,now->r->p);
}

vector<int> query(node *now,int l,int r,int ql,int qr){
    // if(qr<l || r<ql)return vector<point>();
    if(ql<=l&&r<=qr)return now->p;
    if(qr<=mid)return query(now->l,l,mid,ql,qr);
    if(mid<ql)return query(now->r,mid+1,r,ql,qr);
    vector<int> a(32);
    vector<int> b=query(now->l,l,mid,ql,qr);
    vector<int> c=query(now->r,mid+1,r,ql,qr);
    merge(a,b,c);
    return a;
}

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
        char *s=ptr,c; T t;
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

int main(){
    int n; rit(n,k);
    for(int i=1;i<=n;++i){
        p[i].resize(k);
        for(int &j:p[i])rit(j);
        p[i].resize(37,0);
        for(int z=0;z<32;++z){
            for(int j=0;j<5;++j){
                if(z&(1<<j))p[i][5+z]+=p[i][j];
                else p[i][5+z]-=p[i][j];
            }
        }
    }
    build(root=new node(),1,n);
    int q; rit(q); while(q--){
        int c; rit(c);
        if(c==1){
            int x; rit(x);
            p[x].resize(k);
            for(int &j:p[x])rit(j);
            p[x].resize(37,0);
            for(int z=0;z<32;++z){
                for(int j=0;j<5;++j){
                    if(z&(1<<j))p[x][5+z]+=p[x][j];
                    else p[x][5+z]-=p[x][j];
                }
            }
            modify(root,1,n,x);
        }
        else{
            int l,r; rit(l,r);
            vector<int> a=query(root,1,n,l,r);
            int mx=0;
            for(int i=0;i<int(a.size());++i){
                int j=31^i;
                int x=0;
                for(int z=0;z<5;++z)x+=abs(p[a[i]][z]-p[a[j]][z]);
                mx=max(mx,x);
            }
            pit(mx);
        }
    }
}
