#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;
#define ll long long

ll best;
vector<int> chs[100005];
int M,b[100005],c[100005],l[100005];

#define PQ priority_queue<int,vector<int>,less<int>>
#define pipq pair<ll,priority_queue<int,vector<int>,less<int>>*>

pipq dfs(int now){
    vector<pipq> rts;
    int sz=(int)chs[now].size(),bigChild=-1,bigChildIdx=-1;
    pipq rt;rt.first=0;
    rts.resize(sz);
    for(int i=0;i<sz;++i){
        rts[i]=dfs(chs[now][i]);
        if((int)rts[i].second->size()>bigChild){
            bigChild=(int)rts[i].second->size();
            bigChildIdx=i;
            rt.second=rts[i].second;
        }
    }
    if(bigChild==-1){
        PQ *here=new PQ;
        if(c[now]<=M)here->push(c[now]);
        best=max({best,(ll)here->size()*l[now]});
        // cout<<"dfs at now:"<<now<<endl;
        return {c[now]<=M?c[now]:0,here};
    }
    else{
        rt.first=rts[bigChildIdx].first;
        rt.first+=c[now];
        rt.second->push(c[now]);
        for(int i=0;i<sz;++i){
            if(rts[i].second==rt.second)continue;
            while(rts[i].second->size()){
                rt.first+=rts[i].second->top();
                rt.second->push(rts[i].second->top());
                rts[i].second->pop();
            }
            // delete rts[i].second;
        }
        while(rt.first>M){
            rt.first-=rt.second->top();
            rt.second->pop();
        }
        best=max({best,(ll)rt.second->size()*l[now]});
        // cout<<"dfs at now:"<<now<<", rt.second->size()="<<rt.second->size()<<endl;
        return rt;
    }
}


int main(){
    int n,boss;
    scanf("%d%d",&n,&M);
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",b+i,c+i,l+i);
        if(!b[i])boss=i;
        else chs[b[i]].push_back(i);
    }
    dfs(boss);
    printf("%lld\n",best);
}
