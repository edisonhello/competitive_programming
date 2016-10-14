#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
#define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int rit_t,rit_k;
char rit_c;
inline int rit();

struct seg{
    ll v,l,r;
    seg(int x):v(0),l(0),r(0){};
    seg(string x):v(-(1ll<<60)),l(-(1ll<<60)),r(-(1ll<<60)){};
    friend bool operator < (const seg &a,const seg &b){
        return a.v==b.v?(a.l==b.l?(a.r>b.r):a.l>b.l):a.v<b.v;
    }
    friend bool operator > (const seg &a,const seg &b){
        return a.v==b.v?(a.l==b.l?(a.r<b.r):a.l<b.l):a.v>b.v;
    }
    friend seg operator + (const seg &a,const seg &b){
        seg t(0);
        t.v=a.v+b.v;
        t.l=a.l;
        t.r=b.r;
        // cout<<"add! : "<<a.l<<" "<<a.r<<" "<<b.l<<" "<<b.r<<"->"<<t.l<<" "<<t.r;
        if(t.r<t.l || a.r+1!=b.l){
            // cout<<". a strange + happened.";
            // cout<<"a strange + happened.\n";
        }
        // cout<<endl;
        return t;
    }
    friend ostream &operator<<(ostream &ost,const seg &a){
        // ost<<"l:"<<a.l<<" r:"<<a.r<<" v:"<<a.v;
        return ost;
    }
};
struct node{
    node *l,*r;
    seg val,fnt,bak,tot;
    node():l(NULL),r(NULL),val(0),fnt(0),bak(0),tot(0){};
} *root;
int n,q;
ll a[200005];
void build(int,int,node*);
void del(node*);

seg query(int l,int r,node *now,int sl,int sr){
    // cout<<"querying "<<l<<" "<<r<<" for "<<sl<<" "<<sr<<endl;
    if(r<sl || sr<l){
        // cout<<"out of range.\n";
        return (seg)("a"); // may jizz
    }
    if(sl<=l && r<=sr){
        // cout<<"toto in!\n";
        return now->val;
    }
    seg lc=query(l,m,now->l,sl,sr);
    seg rc=query(m+1,r,now->r,sl,sr);
    // cout<<"lc: "<<lc<<" rc: "<<rc<<endl;
    if(lc.l!=(-(1ll<<60)) && rc.l!=(-(1ll<<60))){
        return max(lc,rc);
    }
    if(lc.l!=(-(1ll<<60))){
        return lc;
    }
    if(rc.l!=(-(1ll<<60))){
        return rc;
    }
    return (seg)("a");
}

int main(){
    ios_base::sync_with_stdio(0);
    int cs=0;
    while(cin>>n>>q){
        cout<<"Case "<<(++cs)<<":\n";
        if(root)del(root);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        root=new node();
        build(1,n,root);
        // cout<<"build:over\n";
        while(q--){
            int l,r;
            cin>>l>>r;
            seg ret=query(1,n,root,l,r);
            cout<<ret.l<<" "<<ret.r<<" "<<ret.v<<endl;
        }
    }

}

void build(int l,int r,node *now){
    if(l==r){
        now->val.v=now->fnt.v=now->bak.v=now->tot.v=a[l];
        now->val.l=now->fnt.l=now->bak.l=now->tot.l=l;
        now->val.r=now->fnt.r=now->bak.r=now->tot.r=r;
        return;
    }
    now->l=new node();
    now->r=new node();
    build(l,m,now->l);
    build(m+1,r,now->r);
    // cout<<"get:"<<l<<"~"<<m<<" and "<<m+1<<"~"<<r<<endl;
    // cout<<"counting tot:\n";
    now->tot=now->l->tot+now->r->tot;
    // cout<<"counting fnt:\n";
    now->fnt=max(now->l->fnt,now->l->tot+now->r->fnt);
    // cout<<"counting bak:\n";
    now->bak=max(now->r->bak,now->l->bak+now->r->tot);
    // cout<<"counting val:\n";
    now->val=max(now->l->bak+now->r->fnt,max(now->l->val,now->r->val));
    // cout<<"build:"<<l<<" "<<r<<": ";
    // cout<<"tot("<<now->tot<<") fnt("<<now->fnt<<") bak("<<now->bak<<") val("<<now->val<<")\n";
}

void del(node *now){
    if(now->l)del(now->l);
    if(now->r)del(now->r);
    delete now;
}
