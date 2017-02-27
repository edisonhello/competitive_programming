#include<iostream>
using namespace std;
#include<queue>

struct eg{int u,v,w;};
bool operator>(const eg &a,const eg &b){return a.w>b.w;}
priority_queue<eg,vector<eg>,greater<eg>> pq;
int djs[200005];
int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);djs[x]=y;}
bool C(int x,int y){return F(x)==F(y);}

int main(){
    int n,m;while(cin>>n>>m,n){
        for(int i=0;i<=n;++i){
            djs[i]=i;
        }
        while(pq.size())pq.pop();
        int totw=0;
        while(m--){
            int u,v,w;cin>>u>>v>>w;
            pq.push({u,v,w});
            totw+=w;
        }
        int mst=0;
        for(int i=1;i<n;++i){
            while(C(pq.top().u,pq.top().v))pq.pop();
            U(pq.top().u,pq.top().v);
            mst+=pq.top().w;
        }
        cout<<totw-mst<<endl;
    }
}
