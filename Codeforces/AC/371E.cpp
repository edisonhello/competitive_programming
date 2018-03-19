#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll x[300005],pre[300005];
map<int,int> mid;

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i],mid[x[i]]=i;
    sort(x+1,x+1+n);
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+x[i];
    int k; cin>>k;
    ll mn=(1ll<<61);
    int start=-1;
    ll now=0;
    for(int i=1;i<=k;++i)now+=pre[k]-x[i]*(k-i+1);
    mn=now;
    start=1;
    int l=1,r=k;
    while(r<n){
        now-=pre[r]-pre[l-1]-x[l]*(r-l+1);
        ++l; ++r;
        now+=x[r]*(r-l+1)-pre[r]+pre[l-1];
        if(now<mn){
            mn=now;
            start=l;
        }
    }
    for(int i=start,j=0;j<k;++j,++i){
        cout<<mid[x[i]]<<" ";
    }
    cout<<endl;
}
