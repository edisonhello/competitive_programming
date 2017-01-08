#include<iostream>
using namespace std;
#include<queue>
#include<cmath>

int x[1005],y[1005],d[1005];
struct _{int a,b,c;};
bool operator>(const _ &a,const _ &b){return a.c>b.c;}

priority_queue<_,vector<_>,greater<_>> pq;
bool v[1005];

int F(int x){if(x==d[x])return x;return d[x]=F(d[x]);}
inline void U(int x,int y){x=F(x),y=F(y);if(x==y)return;d[x]=y;}
inline bool C(int x,int y){return F(x)==F(y);}
inline int D(int a,int b){
    if(x[a]==x[b])return abs(y[a]-y[b]);
    if(y[a]==y[b])return abs(x[a]-x[b]);
    return 71222;
}

int main(){
    int ts;cin>>ts;while(ts--){
        int n,a=0;cin>>n;
        while(pq.size())pq.pop();
        for(int i=0;i<n;++i){d[i]=i;cin>>x[i]>>y[i];}

        for(int i=0,dd;i<n;++i){
            for(int j=i+1;j<n;++j){
                dd=D(i,j);
                if(dd==71222)break;
                pq.push({i,j,dd});
            }
        }

        --n;
        for(int i=0;i<n;++i){
            while(pq.size() && C(pq.top().a,pq.top().b))pq.pop();
            if(pq.empty())break;
            U(pq.top().a,pq.top().b);
            // for(int i=0;i<=n;++i)cout<<F(i)<<" ";cout<<endl;
            a+=pq.top().c;
        }
        cout<<a<<endl;
    }
}
