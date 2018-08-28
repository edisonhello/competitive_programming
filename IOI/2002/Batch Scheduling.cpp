#include<iostream>
using namespace std;
#define ll long long
#include<algorithm>
#include<deque>
#include<cstring>

int n;
ll s,pt[1000005],pf[1000005],dp[1000005];
struct line{ll a,b;} ls[1000005];
deque<int> ln;

ll outmin(ll x){return s*pf[n]+x*pf[n];}
bool chk(int l1,int l2,int l3){
    ll a1=ls[l1].a,b1=ls[l1].b;
    ll a2=ls[l2].a,b2=ls[l2].b;
    ll a3=ls[l3].a,b3=ls[l3].b;
    return (b3-b1)*(a1-a2) <= (b2-b1)*(a1-a3);
}
bool uls(int l1,int l2,ll x){
    ll a1=ls[l1].a,b1=ls[l1].b;
    ll a2=ls[l2].a,b2=ls[l2].b;
    return (b2-b1) <= x*(a1-a2);
}
ll curmin(ll x){
    // cout<<"in curmin"<<endl;
    while(ln.size()>1u && uls(ln[0],ln[1],x))ln.pop_front();
    return ls[ln[0]].a*x+ls[ln[0]].b;
}
void insertLine(int i){
    ls[i].a=-pf[i];
    ls[i].b=dp[i]+pf[i]*pt[i]-pf[n]*pt[i]-s*pf[i];
    while(ln.size()>1u && chk(ln[ln.size()-2],ln[ln.size()-1],i))ln.pop_back();
    ln.push_back(i);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    int i;
    for(i=1;i<=n;++i)cin>>pt[i]>>pf[i],pt[i]+=pt[i-1],pf[i]+=pf[i-1];
    for(i=1;i<=n;++i)dp[i]=(1ll<<40);
    insertLine(0);
    for(i=1;i<=n;++i){
        // cout<<"dping "<<i<<endl;
        dp[i]=outmin(pt[i])+curmin(pt[i]);
        insertLine(i);
    }
    cout<<dp[n]<<endl;
}
