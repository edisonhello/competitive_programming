#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define X first
#define Y second
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))

ll n,q;
map<ll,ll> G[1000006];
ll inv[1000006];
ll t[1000006];
inline ll rit();

ll dp(ll now){
    if(t[now])return t[now];
    /*for(ll i=0;i<G[now].size();i++){
        t[now]+=dp(G[now][i].X)+G[now][i].Y;
    }*/
    for(auto i:G[now]){
        t[now]+=dp(i.X)+i.Y;
    }
    return t[now];
}
void update(ll d,ll ch){
    while(inv[d]!=0){
        d=inv[d];
        t[d]+=ch;
    }
}
int main(){
    n=rit(),q=rit();
    for(ll i=0;i<n-1;i++){
        ll a=rit(),b=rit(),m=rit();
        //G[a].push_back({b,m});
        G[a][b]=m;
        inv[b]=a;
    }
    dp(0);
    while(q--){
        ll c=rit(),d,m;
        if(c==0){
            d=rit(),m=rit();
            c=inv[d];
            ll ori=G[c][d];
            G[c][d]=m;
            update(d,m-ori);
        }
        else{
            d=rit();
            printf("%lld\n",t[d]*2);
        }
    }
}

ll rit_t,rit_k;
char rit_c;

inline ll rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
