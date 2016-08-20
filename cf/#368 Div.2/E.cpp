#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
#define xm (x1+x2)/2
#define ym (y1+y2)/2

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
};

struct blub{
    int belong;
    int w;
    blub(){
        belong = w = 0;
    }
};

struct node{
    node *lu,*ld,*ru,*rd;
    int ew[2002];
    node(){
        lu = ld = ru = rd = NULL;
        memset(ew,0,sizeof(ew));
    }
} *root;

int m,n,k;
blub field[2002][2002];
bool rec[2002];

void pull(node *now){
    for(int i=1;i<=k;i++){
        int ewt = 0;
        if(now->lu)ewt += now->lu->ew[i];
        if(now->ld)ewt += now->ld->ew[i];
        if(now->ru)ewt += now->ru->ew[i];
        if(now->rd)ewt += now->rd->ew[i];
        now->ew[i] = ewt;
    }
}

void build(int x1,int y1,int x2,int y2,node *now){
    // cout<<"building "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    if(x1==x2 && y1==y2){
        now->ew[field[x1][y1].belong] = field[x1][y1].w;
        return;
    }
    if(y1==y2){
        now->lu = new node();
        now->ru = new node();
        build(x1,y1,xm,y2,now->lu);
        build(xm+1,y1,x2,y2,now->ru);
        pull(now);
    }
    else if(x1==x2){
        now->lu = new node();
        now->ld = new node();
        build(x1,y1,x2,ym,now->lu);
        build(x1,ym+1,x2,y2,now->ld);
        pull(now);
    }
    else{
        now->lu = new node();
        now->ld = new node();
        now->ru = new node();
        now->rd = new node();
        build(x1,y1,xm,ym,now->lu);
        build(xm+1,y1,x2,ym,now->ru);
        build(x1,ym+1,xm,y2,now->ld);
        build(xm+1,ym+1,x2,y2,now->rd);
        pull(now);
    }
}

int solve(int x1,int y1,int x2,int y2,int sx1,int sy1,int sx2,int sy2,node *now){
    // cout<<"solving "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<sx1<<" "<<sy1<<" "<<sx2<<" "<<sy2<<endl;
    if(sx2<x1||x2<sx1||sy2<y1||y2<sy1){
        return 0;
    }
    int tot=0;
    if(sx1<=x1&&x2<=sx2&&sy1<=y1&&y2<=sy2){
        // cout<<"t"<<endl;
        for(int i=1;i<=k;i++){
            tot += (rec[i]?now->ew[i]:0);
        }
        // cout<<"tot="<<tot<<endl;
    }
    else if(sy1<=y1&&y2<=sy2){
        tot += solve(x1,y1,xm,y2,sx1,sy1,sx2,sy2,now->lu);
        tot += solve(xm+1,y1,x2,y2,sx1,sy1,sx2,sy2,now->ru);
    }
    else if(sx1<=x1&&x2<=sx2){
        tot += solve(x1,y1,x2,ym,sx1,sy1,sx2,sy2,now->lu);
        tot += solve(x1,ym+1,x2,y2,sx1,sy1,sx2,sy2,now->ld);
    }
    else{
        tot += solve(x1,y1,xm,ym,sx1,sy1,sx2,sy2,now->lu);
        tot += solve(xm+1,y1,x2,ym,sx1,sy1,sx2,sy2,now->ru);
        tot += solve(x1,ym+1,xm,y2,sx1,sy1,sx2,sy2,now->ld);
        tot += solve(xm+1,ym+1,x2,y2,sx1,sy1,sx2,sy2,now->rd);
    }
    return tot;
}

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    n=rit();m=rit();k=rit();
    for(int i=1;i<=k;i++){
        int t=rit();
        for(int j=0;j<t;j++){
            int x=rit(),y=rit(),w=rit();
            field[x][y].w = w;
            field[x][y].belong = i;
        }
    }
    for(int i=0;i<2002;i++)rec[i]=1;
    // cout<<"t"<<endl;
    root = new node();
    build(0,0,n,m,root);
    int q=rit();
    for(int i=0;i<q;i++){
        string s;cin>>s;
        if(s[0]=='A'){
            int x1=rit(),y1=rit(),x2=rit(),y2=rit();
            printf("%d\n",solve(0,0,n,m,x1,y1,x2,y2,root));
        }
        else if(s[0]=='S'){
            int sw=rit();
            rec[sw] = !rec[sw];
        }
    }
}
