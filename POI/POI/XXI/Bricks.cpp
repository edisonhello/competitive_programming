/* greedy tutorial by csdn */

#include<bits/stdc++.h>
using namespace std;

void no(){puts("0"); exit(0);}

int a[1000006];



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,p,q,n=0; cin>>k>>p>>q;
    auto cmp=[&](const pair<int,int> &a,const pair<int,int> &b){return a.first==b.first?a.second!=q:a.first<b.first;};
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int i=1;i<=k;++i){
        int c; cin>>c; n+=c;
        if(i==p)--c;
        if(i==q && !(k==1 && n==1))--c;
        if(c<0)no();
        pq.emplace(c,i);
    }
    a[1]=p, a[n]=q;
    pair<int,int> tmp;
    for(int i=2;i<n;++i){
        pair<int,int> pi;
        if(tmp.first)pi=tmp,tmp.first=0;
        else pi=pq.top(),pq.pop();
        if(pi.second==p){
            if(pq.empty())no();
            auto pj=pq.top(); pq.pop();
            p=a[i]=pj.second;
            --pj.first;
            if(pj.first)pq.push(pj);
            // pq.push(pi);
            tmp=pi;
        }
        else{
            p=a[i]=pi.second;
            --pi.first;
            if(pi.first)pq.push(pi);
        }
    }
    if(a[n-1]==a[n])no();
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
    cout<<endl;
}
// 74 pts, little TLE
