#include<bits/stdc++.h>
using namespace std;

int xs[100005],to[1000006],bit[1000006];

void add(int x,int v){
    for(;x<1000006;x+=x&-x)bit[x]=min(bit[x],v);
}
int query(int x,int v=0x3f3f3f3f){
    for(;x;x-=x&-x)v=min(v,bit[x]);
    return v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>xs[i];
    int a,b; cin>>a>>b;
    sort(xs,xs+n);
    n=unique(xs,xs+n)-xs;
    
    for(int i=0;i<n;++i){
        int x=xs[i];
        int st=((b-1)/x+1)*x;
        // cout<<"i "<<i<<" "<<x<<endl;
        for(;st<=a;st+=x)/* cout<<st<<" "<<st-b<<endl, */to[st-b]=x;
    }


    memset(bit,0x3f,sizeof(bit));
    add(a-b+1,0);

    for(int i=a-1;i>=b;--i){
        int v=query(min(i-b+1+(to[i-b]?to[i-b]-1:1),1000003))+1;
        if(to[i-b]==0)add(i-b+1,v);
        else add(i-b+1,v);
        // cout<<i<<" "<<to[i]<<" "<<v<<endl;
    }
    cout<<query(1)<<endl;
}
