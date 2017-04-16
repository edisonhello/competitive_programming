#include<bits/stdc++.h>
using namespace std;

pair<int,int> lc[100009],uc[100009];
int et[100009];

void nom(int n){
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(0);
    sort(lc,lc+n,[](const pair<int,int> &a,const pair<int,int> &b){return a.first<b.first;});
    for(int i=0;i<n;++i){
        if(pq.top()>lc[i].first)pq.push(lc[i].second+1);
        else{
            pq.pop(); pq.push(lc[i].second+1);
        }
    }
    cout<<pq.size()<<endl;
    exit(0);
}
void non(int m){
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(0);
    sort(uc,uc+m,[](const pair<int,int> &a,const pair<int,int> &b){return a.second<b.second;});
    for(int i=0;i<m;++i){
        if(uc[i].second-pq.top()<uc[i].first){
            pq.push(uc[i].first);
        }
        else{
            pq.push(pq.top()+uc[i].first); pq.pop();
        }
    }
    cout<<pq.size()<<endl;
    exit(0);
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>lc[i].first>>lc[i].second;
    int m;cin>>m;
    for(int i=0;i<m;++i)cin>>uc[i].first>>uc[i].second;
    if(!m)nom(n);
    if(!n)non(m);
}
