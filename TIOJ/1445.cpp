#include<iostream>
#include<queue>
using namespace std;

struct eg{
    int s,e,c;
    eg& operator=(const eg &a){this->s=a.s,this->e=a.e,this->c=a.c;}
    bool operator<(const eg &a)const{return this->c<a.c;}
    bool operator>(const eg &a)const{return this->c>a.c;}
};

priority_queue<eg,vector<eg>,greater<eg>> pq;
bool mst[1005][1005],v[1005];
int n,m,djs[1005],G[1005][1005];

int F(int x){
    if(djs[x]==x)return x;
    else return djs[x]=F(djs[x]);
}
inline void U(int x,int y){
    x=F(x);y=F(y);
    djs[x]=y;
}
inline bool C(int x,int y){
    return F(x)==F(y);
}

int dfs(int now,int fn){
    // cout<<"dfs in "<<now<<endl;
    if(now==fn){
        return -(1<<30);
    }
    v[now]=1;
    for(int i=1;i<=n;++i){
        if(mst[now][i] && !v[i]){
            int rt=dfs(i,fn);
            if(rt){
                return max(G[now][i],rt);
            }
        }
    }
    // cout<<now<<" rt0"<<endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    eg tmp;while(m--){
        cin>>tmp.s>>tmp.e>>tmp.c;
        G[tmp.s][tmp.e]=G[tmp.e][tmp.s]=tmp.c;
        pq.push(tmp);
    }
    for(int i=1;i<=n;++i)djs[i]=i;
    int pwr=0,_;bool gotmine=0;eg mine;
    for(_=0;_<n-1;++_){
        while(pq.size()){
            if(C(pq.top().s,pq.top().e)){
                if(!gotmine){gotmine=1;mine=pq.top();}
                pq.pop();
            }
            else break;
        }
        if(pq.empty())break;
        // cout<<pq.top().s<<" "<<pq.top().e<<" "<<pq.top().c<<endl;
        pwr+=pq.top().c;
        U(pq.top().s,pq.top().e);
        mst[pq.top().s][pq.top().e]=mst[pq.top().e][pq.top().s]=1;
        pq.pop();
    }
    if(_!=n-1){cout<<"-1 -1\n";return 0;}
    // cout<<_<<" "<<pwr<<endl;
    cout<<pwr<<" ";
    if(mine.s==0 && pq.size())mine=pq.top();
    if(mine.s==0)cout<<"-1\n";
    else cout<<pwr+mine.c-dfs(mine.s,mine.e)<<endl;
}
