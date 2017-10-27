#include<bits/stdc++.h>
using namespace std;

struct info{int x,t,i;
info(int x=0,int t=0,int i=0):x(x),t(t),i(i){}};
bool operator<(const info &a,const info &b){return a.x<b.x;}
vector<info> lr,du;
int l[100005],r[100005],d[100005],u[100005];
bool v[100005];
bool ok(int *l,int *r,vector<info> &lr){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int ptr=0;
    memset(v,0,sizeof(v));
    for(int i=0;i<=100000;++i){
        // cout<<"i="<<i<<endl;
        while(ptr<lr.size() && lr[ptr].x<=i){
            // cout<<"ptr="<<ptr<<endl;
            if(lr[ptr].t==1){
                // cout<<"ptr="<<ptr<<endl;
                pq.push({r[lr[ptr].i]+1,lr[ptr].i});
            }
            else{
                if(!v[lr[ptr].i])return 0;
            }
            ++ptr;
            // cout<<"ptr="<<ptr<<endl;
        }

        if(pq.size()){
            // cout<<pq.top().second<<endl;
            v[pq.top().second]=1;
            pq.pop();
        }
    }
    return 1;
}
int main(){
    int n; while(cin>>n){
        lr.clear(); du.clear();
        for(int i=0;i<n;++i){
            cin>>l[i]>>r[i]>>d[i]>>u[i];
            lr.emplace_back(l[i],1,i);
            lr.emplace_back(r[i]+1,-1,i);
            du.emplace_back(d[i],1,i);
            du.emplace_back(u[i]+1,-1,i);
        }
        sort(lr.begin(),lr.end());
        sort(du.begin(),du.end());
        if(ok(l,r,lr) && ok(d,u,du))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
