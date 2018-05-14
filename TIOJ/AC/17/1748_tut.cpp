#include<bits/stdc++.h>
using namespace std;

int djs[400005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}
bool C(int x,int y){return F(x)==F(y);}

struct {
    int x,y,c;
} res[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    for(int i=0;i<400005;++i)djs[i]=i;
    for(int i=1;i<=k;++i){
        cin>>res[i].x>>res[i].y>>res[i].c;
        if(res[i].x%2==0 && res[i].y%2==0)res[i].c^=1;
        if(res[i].c){
            if(C(res[i].x,res[i].y+n) || C(res[i].x+n+m,res[i].y+n+n+m))exit((cout<<0<<endl,0));
            U(res[i].x,res[i].y+n+n+m); U(res[i].x+n+m,res[i].y+n);
        }
        else{
            if(C(res[i].x,res[i].y+n+n+m) || C(res[i].x+n+m,res[i].y+n))exit((cout<<0<<endl,0));
            U(res[i].x,res[i].y+n); U(res[i].x+n+m,res[i].y+n+n+m);
        }
        // for(int i=1;i<=14;++i)cout<<F(i)<<" "; cout<<endl;
    }
    int ans=1;
    for(int i=1;i<=n;++i){
        if(!C(i,1+n) && !C(i,1+n+n+m))ans=ans*2%1000000000,U(i,1+n),U(i+n+m,1+n+n+m);
        // else cout<<"i "<<i<<" jizz"<<endl;
        // for(int i=1;i<=14;++i)cout<<F(i)<<" "; cout<<endl;
    }
    for(int i=1;i<=m;++i){
        if(!C(1,i+n) && !C(1,i+n+n+m))ans=ans*2%1000000000,U(1,i+n),U(1+n+m,i+n+n+m);
        // else cout<<"j "<<i<<" jizz"<<endl;
        // for(int i=1;i<=14;++i)cout<<F(i)<<" "; cout<<endl;
    }
    cout<<ans<<endl;
}
