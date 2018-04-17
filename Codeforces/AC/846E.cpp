#pragma GCC optimize("O")
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005],b[100005],k[100005];
int pa[100005];
int sons[100005];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=2;i<=n;++i){
        cin>>pa[i]>>k[i];
        ++sons[pa[i]];
    }
    queue<int> le;
    for(int i=1;i<=n;++i)if(sons[i]==0)le.push(i);
    while(le.size()){
        int now=le.front(); le.pop();
        if(now==1){
            if(a[now]>=b[now])cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            break;
        }
        if(b[now]==a[now]);
        else if(b[now]>a[now]){
            ll need=b[now]-a[now];
            ll tk=need*k[now];
            if(tk/need!=k[now])exit((cout<<"NO"<<endl,0));
            a[pa[now]]-=tk;
            if(a[pa[now]]<-2e17)exit((cout<<"NO"<<endl,0));
        }
        else{
            ll mo=a[now]-b[now];
            a[pa[now]]+=mo;
        }
        --sons[pa[now]];
        if(sons[pa[now]]==0)le.push(pa[now]);
    }
}
