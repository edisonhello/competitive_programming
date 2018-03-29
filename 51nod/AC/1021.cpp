#include<bits/stdc++.h>
using namespace std;

int prv[130005],nxt[130005],val[130005],front,back;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; 
    back=n+1;
    for(int i=1;i<=n;++i)cin>>val[i];
    val[0]=val[n+1]=1<<30;
    for(int i=0;i<=n+1;++i)prv[i]=i-1;
    for(int i=0;i<=n;++i)nxt[i]=i+1; nxt[n+1]=-1;
    long long ans=0;
    int $=n+2;

    auto del=[&](int id){
        nxt[prv[id]]=nxt[id];
        prv[nxt[id]]=prv[id];
    };
    auto ins=[&](int id,int nval){
        val[$]=nval;
        nxt[$]=nxt[id];
        prv[$]=id;
        prv[nxt[$]]=$;
        nxt[id]=$;
        ++$;
    };

    for(int cnt=1;cnt<n;++cnt){
        // cout<<"cnt: "<<cnt<<endl;
        int now=nxt[front];
        while(!(val[prv[now]]<=val[nxt[now]]))now=nxt[now];
        int nval=val[prv[now]]+val[now];
        del(prv[now]), now=prv[now], del(nxt[now]);
        while(val[now]<=nval)now=prv[now];
        ins(now,nval);
        ans+=nval;
    }
    cout<<ans<<endl;
}
