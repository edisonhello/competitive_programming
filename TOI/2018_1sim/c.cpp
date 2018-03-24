#include<bits/stdc++.h>
using namespace std;
#define lb(x) ((x)&-(x))

const int maxn=3232;

int a[maxn];

int bit[maxn];
void add(int x,int v){
    x=maxn-1-x;
    for(;x<maxn;x+=lb(x)){
        bit[x]=max(bit[x],v);
    }
}
int query(int x,int v=0){
    x=maxn-1-x;
    for(;x;x-=lb(x)){
        v=max(v,bit[x]);
    }
    return v;
}

int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        int mx=0;
        memset(bit,0,sizeof(bit));
        for(int j=i;j<=n;++j){
            int qu=query(a[j]);
            ++qu;
            mx=max(mx,qu);
            if(mx==k){
                ++ans;
                cout<<i<<" "<<j<<endl;
            }
            add(a[j],qu);
        }
    }
    cout<<ans<<endl;

}
