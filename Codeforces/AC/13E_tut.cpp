#include<bits/stdc++.h>
using namespace std;

#define id(x) ((x)/blksz)

int a[100005],nxt[100005],cnt[100005],last[100005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    int blksz=ceil(sqrt(n));
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=n;i>=1;--i){
        int to=i+a[i];
        if(to>n || id(to)!=id(i)){
            nxt[i]=to;
            cnt[i]=1;
            last[i]=i;
        }
        else{
            nxt[i]=nxt[to];
            cnt[i]=cnt[to]+1;
            last[i]=last[to];
        }
    }
    while(m--){
        int t; cin>>t;
        if(t==1){
            int i; cin>>i;
            int an=0,la;
            while(i<=n){
                an+=cnt[i];
                la=last[i];
                i=nxt[i];
            }
            cout<<la<<" "<<an<<'\n';
        }
        else{
            int x,v; cin>>x>>v;
            a[x]=v;
            for(int i=x;i;--i){
                if(id(i)!=id(x))break;
                int to=i+a[i];
                if(to>n || id(to)!=id(i)){
                    nxt[i]=to;
                    cnt[i]=1;
                    last[i]=i;
                }
                else{
                    nxt[i]=nxt[to];
                    cnt[i]=cnt[to]+1;
                    last[i]=last[to];
                }
            }
        }
    }
}

