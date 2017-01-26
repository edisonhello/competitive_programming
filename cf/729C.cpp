#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define X first
#define Y second
#include<utility>
#include<vector>

struct inf{int n,l;};
bool operator>(const inf &a,const inf &b){return a.n==b.n?a.l<b.l:a.n>b.n;}
bool operator<(const inf &a,const inf &b){return a.n==b.n?a.l>b.l:a.n<b.n;}
bool cmp_ol_pr(const pair<int,int> &a,const pair<int,int> &b){return a.Y==b.Y?a.X<b.X:a.Y<b.Y;}

vector<pair<int,int>> car;
vector<int> gs;
priority_queue<inf,vector<inf>,less<inf>> pq;

int main(){
    int n,k,s,t;
    cin>>n>>k>>s>>t;k+=2;
    if(t<s){cout<<-1<<endl;return 0;}
    car.resize(n);
    for(int i=0;i<n;++i)cin>>car[i].X>>car[i].Y;
    sort(car.begin(),car.end(),cmp_ol_pr);
    gs.resize(k);
    for(int i=1;i<k-1;++i)cin>>gs[i];gs[k-1]=s;
    sort(gs.begin(),gs.end());
    int maxd=0;
    for(int i=1;i<k;++i){
        pq.push({(gs[i]-gs[i-1])<<1,gs[i]-gs[i-1]});
        maxd=max(maxd,gs[i]-gs[i-1]);
    }
    int buffer=t-s;
    while(buffer>0){
        if(pq.size() && pq.top().n<=pq.top().l){
            break;
        }
        --buffer;
        pq.push({pq.top().n-1,pq.top().l});
        pq.pop();
    }
    int ol=pq.top().n;
    // cout<<"oil: "<<ol<<endl;
    // for(auto &i:car){
    //     cout<<i.X<<" "<<i.Y<<endl;
    // }
    auto lb=lower_bound(car.begin(),car.end(),pair<int,int>(-1,ol),cmp_ol_pr);
    if(lb==car.end())cout<<-1<<endl;
    else cout<<lb->X<<endl;
}
