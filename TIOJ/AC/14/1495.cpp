#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

int n,m;
const int X=1000000;
const int Z=1e9+7;
int djs[2000006],sz[2000006];
bool app[2000006];
// int grps;

int F(int a){
    if(djs[a]==a) return a;
    else return djs[a]=F(djs[a]);
}
void U(int a,int b){
    a=F(a);
    b=F(b);
    if(sz[a]>sz[b])swap(a,b);
    djs[a]=b;
    sz[b]+=sz[a];
    return;
}
int C(int a,int b){
    return F(a)==F(b);
}

ll _pow(ll base,int p){
    ll rt=1;
    while(p){
        if(p&1)rt=rt*base%Z;
        base=base*base%Z;
        p>>=1;
    }
    return rt;
}

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>n>>m;
    for(int i=0;i<2000005;++i){
        djs[i]=i;
        sz[i]=1;
    }

    while(m--){
        int a,b,d;
        cin>>a>>b>>d;
        if(!d){
            if(C(a,b) || C(a+X,b+X)){
                cout<<0<<'\n';
                return 0;
            }
            U(a+X,b);
            U(a,b+X);
            // grps--;

        }
        else if(d){
            if(C(a+X,b) || C(a,b+X)){
                cout<<0<<'\n';
                return 0;
            }
            U(a,b);
            U(a+X,b+X);
            // grps--;
        }
    }
    // cout<<grps<<endl;

    int grps=0,ii,i;
    for(i=0;i<n;++i){
        ii=F(i);
        if(!app[ii]){
            app[ii]=1;
            grps++;
        }
    }
    for(i=0+X;i<n+X;++i){
        ii=F(i);
        if(!app[ii]){
            app[ii]=1;
            grps++;
        }
    }
    cout<<_pow(2l,((grps>>1)-1))<<'\n';
}
