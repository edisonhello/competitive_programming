#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#include<deque>
#include<assert.h>
#define int long long

int n,k;
ll pa[500005],dp[500005];
struct line{ll a,b;} ls[500005];
deque<int> ln;

bool chk(int l1,int l2,int l3){
    ll a1=ls[l1].a,b1=ls[l1].b;
    ll a2=ls[l2].a,b2=ls[l2].b;
    ll a3=ls[l3].a,b3=ls[l3].b;
    // return (b1-b3)*(a2-a1) <= (b1-b2)*(a3-a1);
    return min((ll)(l3+k)*(a2-a3)*(a1-a2),(b2-b1)*(a2-a3)) >= (b3-b2)*(a1-a2);
}
bool uls(int l1,int l2,ll cpt){
    ll a1=ls[l1].a,b1=ls[l1].b;
    ll a2=ls[l2].a,b2=ls[l2].b;
    return (b1-b2) <= cpt*(a2-a1);
}
void insertLine(int i){
    ls[i].a=2*i;
    ls[i].b=dp[i]+pa[i]-i*i;
    while(ln.size()>1u && chk(ln[ln.size()-2],ln[ln.size()-1],i))ln.pop_back();
    ln.push_back(i);
}
ll gt(int i){
    while(ln.size()>1u && uls(ln[0],ln[1],i))ln.pop_front();
    while(ln.size() && ln[0]<i-k)ln.pop_front();
    if(ln.empty())assert(1==0);
    return ls[ln[0]].a*i+ls[ln[0]].b;
}
main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>pa[i];
    reverse(pa+1,pa+1+n);
    for(int i=1;i<=n;++i)pa[i]+=pa[i-1];
    insertLine(0);
    for(int i=1;i<=n;++i){
        dp[i]=gt(i)-i*i;
        insertLine(i);
    }
    cout<<dp[n]<<endl;
}
