#include<bits/stdc++.h>
using namespace std;
#define lb(x) ((x)&-(x))

// p>=j

int bit[2000006],pre[2000006],erp[2000006],rto[2000006],lto[2000006];
int query1(int x,int rt=0x3f3f3f3f){
    for(;x;x-=lb(x))rt=min(rt,bit[x]);
    return rt;
}
void add1(int x,int v){
    for(;x<2000006;x+=lb(x))bit[x]=min(bit[x],v);
}
int query2(int x,int rt=-1){
    for(;x;x-=lb(x))rt=max(rt,bit[x]);
    return rt;
}
void add2(int x,int v){
    for(;x<2000006;x+=lb(x))bit[x]=max(bit[x],v);
}

int main(){
    // int n; cin>>n;
    string s; cin>>s>>s;
    int n=s.size();
    for(int i=0;i<n;++i){
        pre[i]=(s[i]=='p'?1:-1);
        if(i)pre[i]+=pre[i-1];
    }
    for(int i=n-1;i>=0;--i){
        erp[i]=(s[i]=='p'?1:-1);
        erp[i]+=erp[i+1];
    }
    memset(bit,0x3f,sizeof(bit));
    for(int i=n-1;i>=0;--i){
        add1(pre[i]+1000002,i);
        int q=query1((i?pre[i-1]-1:-1)+1000002);
        if(q==0x3f3f3f3f)rto[i]=n;
        else rto[i]=q;
    }
    memset(bit,0xff,sizeof(bit));
    for(int i=0;i<n;++i){
        add2(erp[i]+1000002,i);
        int q=query2((erp[i+1]-1)+1000002);
        lto[i]=q;
    }
    // for(int i=0;i<n;++i)cout<<rto[i]<<" "; cout<<endl;
    // for(int i=0;i<n;++i)cout<<lto[i]<<" "; cout<<endl;
    int ans=0;
    /* tutorial */
    for(int i=0,j;i<n;i=j){
        j=i;
        for(int ii=i;ii<rto[i];++ii){
            if(lto[ii]<i)ans=max(ans,ii-i+1),j=ii;
        }
        if(j==i)++j;
    }
    /* by CBD (cbdcoding) */
    cout<<ans<<endl;
}
