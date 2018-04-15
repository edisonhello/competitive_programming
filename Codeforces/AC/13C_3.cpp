#include<vector>
#include<iostream>
#include<deque>
#include<algorithm>
#include<queue>
using namespace std;

int n,a[5222];
long long ans=1ll<<60;

struct info{
    int l,r;
    priority_queue<int,vector<int>,less<int>> *pq;
    info(int l,int r,int val):l(l),r(r){
        pq=new priority_queue<int,vector<int>,less<int>>();
        pq->push(val);
    }
    int val(){
        return pq->top();
    }
    void merge(info &ano){
        if(ano.pq->size()>pq->size())swap(pq,ano.pq);
        while(ano.pq->size())pq->push(ano.pq->top()),ano.pq->pop();
        l=min(l,ano.l);
        r=max(r,ano.r);
        while(pq->size()>(r-l+2)/2)pq->pop();
    }
};

void meow(){
    deque<info> dq;
    for(int i=1;i<=n;++i){
        info now(i,i,a[i]);
        // cout<<"i: "<<i<<" , a[i]: "<<a[i]<<endl;
        while(dq.size() && now.val()<dq.back().val()){
            // cout<<"merge! "<<now.val()<<" "<<dq.back().val()<<endl;
            now.merge(dq.back());
            dq.pop_back();
        }
        dq.push_back(now);
    }
    // cout<<"finale dq size: "<<dq.size()<<endl;
    long long cost=0;
    for(int i=0;i<dq.size();++i){
        // cout<<"l,r is "<<dq[i].l<<" "<<dq[i].r<<" with val "<<dq[i].val()<<endl;
        for(int j=dq[i].l;j<=dq[i].r;++j){
            cost+=abs(a[j]-dq[i].val());
        }
    }
    ans=min(ans,cost);
    // cout<<"got cost "<<cost<<endl;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    meow();
    cout<<ans<<endl;
}
