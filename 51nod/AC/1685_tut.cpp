#include<bits/stdc++.h>
using namespace std;

int n,pre[100005],a[100005];
int bit[2][200005];

void add(int *bit,int x,int v){
    x+=100002;
    for(;x<200005;x+=x&-x)bit[x]+=v;
}
int query(int *bit,int x,int v=0){
    x+=100002;
    for(;x;x-=x&-x)v+=bit[x];
    return v;
}

// pre[j]*2-j > pre[i-1]*2-(i-1)
long long calc(int eg){
    memset(bit,0,sizeof(bit));
    long long rt=0;
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+(a[i]>=eg);
    add(bit[1],0,1);
    for(int i=1;i<=n;++i){
        rt+=query(bit[i&1],pre[i]*2-i);
        add(bit[!(i&1)],pre[i]*2-i,1);
    }
    return rt;
}

int main(){
    cin>>n;
    long long k; cin>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    long long L=0,R=(1ll<<31)-1;
    while(R>L){
        long long mid=(L+R+1)>>1;
        if(calc(mid)>=k)L=mid;
        else R=mid-1;
    }
    cout<<L<<endl;
}
