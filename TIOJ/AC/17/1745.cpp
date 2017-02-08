#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#include<set>
#include<deque>

int n;
ll pre[1000006],dp[1000006],a,b,c;
struct line{ll a,b;} ls[1000006];
deque<int> lnm;

inline ll outmax(ll x){
    return a*x*x+b*x;
}
bool told(int l1,int l2,ll x){
    ll a1=ls[l1].a,b1=ls[l1].b;
    ll a2=ls[l2].a,b2=ls[l2].b;
    // cout<<"cmp line "<<l1<<" and "<<l2<<" to "<<x<<endl;
    return (b1-b2)<=(a2-a1)*x;
}
inline ll curmax(ll x){ //find a line have y(x) max
    while(lnm.size()>1u && told(lnm[0],lnm[1],x)){
        // cout<<"throw front line"<<endl;
        lnm.pop_front();
    }
    // cout<<"front line number:"<<lnm[0]<<endl;
    return ls[lnm[0]].a*x+ls[lnm[0]].b;
}
inline bool chk(int l1,int l2,int l3){
    ll a1=ls[l1].a,b1=ls[l1].b;
    ll a2=ls[l2].a,b2=ls[l2].b;
    ll a3=ls[l3].a,b3=ls[l3].b;
    return (b3-b1)*(a2-a1) >= (b2-b1)*(a3-a1);
}
inline void insertLine(int n){ // new line L:y = -2avx + avv - bv + c
    ls[n].a=-2*a*pre[n];
    ls[n].b=a*pre[n]*pre[n]-b*pre[n]+c+dp[n];
    // cout<<"new line "<<n<<" : y="<<ls[n].a<<"x+"<<ls[n].b<<endl;
    while(lnm.size()>1u && chk(lnm[lnm.size()-2],lnm[lnm.size()-1],n)){
        // cout<<"throw back line"<<endl;
        lnm.pop_back();
    }
    lnm.push_back(n);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;++i)cin>>pre[i],pre[i]+=pre[i-1],dp[i]=-(1ll<<60);
    lnm.push_back(0);ls[0].b=c;
    for(int i=1;i<=n;++i){
        // cout<<"dping for "<<i<<endl;
        dp[i]=outmax(pre[i])+curmax(pre[i]);
        insertLine(i);
        // cout<<"dp[i]="<<dp[i]<<endl;
    }
    cout<<dp[n]<<endl;
    // cout<<"dp :";for(int i=1;i<=n;++i)cout<<dp[i]<<" ";cout<<endl;
    // cout<<"pre:";for(int i=1;i<=n;++i)cout<<pre[i]<<" ";cout<<endl;
    // cout<<"omx:";for(int i=1;i<=n;++i)cout<<outmax(pre[i])<<" ";cout<<endl;
}
