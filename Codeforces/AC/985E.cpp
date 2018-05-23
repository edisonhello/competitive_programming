#include<bits/stdc++.h>
using namespace std;

int bit[500005];
int a[500005];

int query(int x,int v=0){
    for(;x;x-=x&-x)v+=bit[x];
    return v;
}
void add(int x,int v){
    for(;x<500005;x+=x&-x)bit[x]+=v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,d; cin>>n>>k>>d;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    if(a[k]<=a[1]+d)add(k,1);
    int ptr=1;
    for(int i=k+1;i<=n;++i){
        while(a[ptr]+d<a[i])++ptr;
        if(i-ptr+1<k)continue;
        if(ptr==1 || query(i-k)-query(ptr-2))add(i,1);
        // cout<<i<<" trans from "<<i-k<<" to "<<ptr-1<<endl;
        // cout<<i<<" "<<ptr<<endl;
    }
    if(query(n)-query(n-1))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
