#include<bits/stdc++.h>
using namespace std;

struct edge{
    int l,r,c;
    friend bool operator > (const edge &l,const edge &r){
        return l.c>r.c;
    }
};

int m,n,i,j,c,lo,s[10005],ans,sz[10005],apped[10005],appcnt;
priority_queue<edge,vector<edge>,greater<edge> > pq;
void C();
void Init();

int F(int a){
    if(a==s[a])return a;
    return s[a] = F(s[a]);
}
inline bool U(int a,int b){
    a=F(a),b=F(b);
    if(a==b)return 0;
    if(sz[b]<sz[a])swap(a,b);
    s[a]=b;
    sz[b]+=sz[a];
    return 1;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n>>m && m && n){
        C();

        for(lo=0;lo<m;lo++){
            cin>>i>>j>>c;
            pq.push({i,j,c});
        }

        Init();

        while(pq.size()){
            edge e=pq.top();
            pq.pop();
            if(U(e.l,e.r)){
                ans+=e.c;
            }
        }
        if(sz[F(1)]!=n){
            cout<<"-1\n";
        }
        else{
            cout<<ans<<endl;
        }
    }
}

inline void C(){
    memset(s,0,sizeof(s));
    memset(sz,0,sizeof(sz));
    ans=0;
    while(pq.size())pq.pop();
}
inline void Init(){
    for(lo=0;lo<=n;lo++){
        s[lo]=lo;
        sz[lo]=1;
    }
}
