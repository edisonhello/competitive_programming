#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;

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

struct node{
    ll v;
    node *l,*r;
    node():v(0),l(NULL),r(NULL){}
    // friend bool operator>(const node &lhs,const node &rhs){
    //     return lhs.v>rhs.v;
    // }
};

bool cmp(const node* a,const node* b){
    return a->v>b->v;
}

ll n,t;
node* ptr;
ll ans;

priority_queue<node*,vector<node*>, decltype(&cmp) > pq(cmp);

void dfs(node* now,int dis){
    // cout<<"now: l="<<now->l<<", r="<<now->r<<", v="<<now->v<<", dis="<<dis<<endl;
    if(now->l){
        dfs(now->l,dis+1);
    }
    if(now->r){
        dfs(now->r,dis+1);
    }
    if(now->l==0 && now->r==0){
        // cout<<"now v="<<now->v;
        ans+=(now->v*dis);
        // cout<<", dis="<<dis<<endl;
    }
}

int main(){
    n=rit();
    for(int i=0;i<n;i++){
        ptr = new node();
        ptr->v=rit();
        pq.push(ptr);
    }

    while(pq.size()>1){
        ptr = new node();
        ptr->l = pq.top();pq.pop();
        ptr->r = pq.top();pq.pop();
        ptr->v = ptr->l->v + ptr->r->v;
        pq.push(ptr);
    }
    dfs(pq.top(),0);
    cout<<ans<<endl;
}
