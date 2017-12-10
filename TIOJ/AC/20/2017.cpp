#include<bits/stdc++.h>
using namespace std;

long long a[1000006],pre[1000006];
vector<long long> num;
int bit[1000006];

#define lb(x) ((x)&-(x))

void upd(int x,int v){
    for(;x<1000006;x+=lb(x))bit[x]=min(bit[x]?:9999999,v);
}
int qry(int x,int v=9999999){
    for(;x;x-=lb(x))v=min(v,(bit[x]?:9999999));
    return v;
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i],num.push_back(pre[i]); num.push_back(0);
    sort(num.begin(),num.end()); for(int i=0;i<=n;++i)pre[i]=lower_bound(num.begin(),num.end(),pre[i])-num.begin()+1;
    long long ans=0;
    for(int i=n;i>=1;--i){
        if(a[i]<0)ans+=n-i+1;
        else{
            int q=qry(pre[i-1]-1);
            if(q!=9999999)ans+=n-q+1;
        }
        // cout<<i<<" "<<pre[i]<<" "<<ans<<" "<<qry(pre[i-1]-1)<<endl;
        upd(pre[i],i);
    }
    cout<<ans<<endl;
}
