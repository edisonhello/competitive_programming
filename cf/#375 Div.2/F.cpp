#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))

int rit_t,rit_k;
char rit_c;
inline int rit();

int n,m;
vint G[200005];
int s,t,ds,dt;
bitset<200005> v;
int d[200005];
vector<pii> rec;

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin>>s>>t>>ds>>dt;

    MSB(d);
    queue<pii> q;
    int fst;
    for(fst=1;fst==s||fst==t;fst++){}
    // q.push(fst);
    v[fst]=1;
    for(int i=0;i<G[fst].size();i++){
        if(G[fst][i]==s||G[fst][i]==t)continue;
        q.push({fst,G[fst][i]});
    }
    int nodes=0;
    while(q.size()){
        if(q.size() && v[q.front().Y]){
            q.pop();
        }
        if(q.empty()){
            break;
        }
        v[q.front().Y]=1;
        nodes++;
        rec.push_back({q.front().X,q.front().Y});
        for(int i=0;i<G[q.front().Y].size();i++){
            if(G[q.front().Y][i]==s||G[q.front().Y][i]==t)continue;
            q.push({q.front().Y,G[q.front().Y][i]});
        }
    }
    if(nodes==n-2)
}


inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar_unlocked();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar_unlocked();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
