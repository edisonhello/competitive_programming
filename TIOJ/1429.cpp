#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> chs[100005];
priority_queue<int,vector<int>,less<int>> pq[100005];
int best,pqPointer[100005],pqCost[100005],M,b[100005],c[100005],l[100005];

void dfs(int now){
    for(int i=0;i<(int)chs[now].size();++i){
        dfs(chs[now][i]);
    }
    int mxSize=1,mxPQ=now;
    for(int i=0;i<(int)chs[now].size();++i){
        if((int)pq[pqPointer[chs[now][i]]].size()>mxSize){
            mxSize=(int)pq[pqPointer[chs[now][i]]].size();
            mxPQ=pqPointer[chs[now][i]];
        }
    }
    pqPointer[now]=mxPQ;
    pq[pqPointer[now]].push(c[now]);
    pqCost[pqPointer[now]]+=c[now];
    for(int i=0;i<(int)chs[now].size();++i){
        if(chs[now][i]==mxPQ)continue;
        while(pq[pqPointer[chs[now][i]]].size()){
            pqCost[pqPointer[now]]+=pq[pqPointer[chs[now][i]]].top();
            pq[pqPointer[now]].push(pq[pqPointer[chs[now][i]]].top());
            pq[pqPointer[chs[now][i]]].pop();
        }
    }
    while(pqCost[pqPointer[now]]>M){
        pqCost[pqPointer[now]]-=pq[pqPointer[now]].top();
        pq[pqPointer[now]].pop();
    }
    cout<<"in point "<<now<<" , "<<(int)pq[pqPointer[now]].size()*l[now]<<endl;
    best=max({best,(int)pq[pqPointer[now]].size()*l[now]});
}


int main(){
    ios_base::sync_with_stdio(0);
    int n,boss;cin>>n>>M;
    for(int i=0;i<n;++i){
        cin>>b[i]>>c[i]>>l[i];
        if(!b[i])boss=i;
        else chs[b[i]].push_back(i);
        pqPointer[i]=i;
    }
    dfs(boss);
    cout<<best<<endl;
}
