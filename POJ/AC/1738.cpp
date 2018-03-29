#include<iostream>
using namespace std;

int prv[130005],nxt[130005],val[130005],front,back,_;

void del(int id){
    nxt[prv[id]]=nxt[id];
    prv[nxt[id]]=prv[id];
}
void ins(int id,int nval){
    val[_]=nval;
    nxt[_]=nxt[id];
    prv[_]=id;
    prv[nxt[_]]=_;
    nxt[id]=_;
    ++_;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; while(cin>>n,n){
       back=n+1; front=0;
        for(int i=1;i<=n;++i)cin>>val[i];
        val[0]=val[n+1]=1<<30;
        for(int i=0;i<=n+1;++i)prv[i]=i-1;
        for(int i=0;i<=n;++i)nxt[i]=i+1; nxt[n+1]=-1;
        long long ans=0;
        _=n+2;
    
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
}
