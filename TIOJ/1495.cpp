#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

int n,m;
const int X=1000000;
const int Z=1e9+7;
int djs[2000006];
// int grps;

int F(int a){
    if(djs[a]==a) return a;
    else return djs[a]=F(djs[a]);
}
void U(int a,int b){
    a=F(a);
    b=F(b);
    djs[a]=b;
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
    for(int i=0;i<2000005;i++)djs[i]=i;
    // grps=n;
    while(m--){
        int a,b,d;
        cin>>a>>b>>d;
        if(d==0){
            if(C(a,b) || C(a+X,b+X)){
                cout<<0<<'\n';
                return 0;
            }
            U(a+X,b);
            U(a,b+X);
            // grps--;

        }
        else if(d==1){
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

    int grps=1;
    for(int i=1;i<n;i++){
        if(F(i)-F(i-1)&&abs(F(i)-F(i-1)-X)){
            grps++;
            break;
        }
    }
    cout<<_pow(2l,grps-1)<<'\n';
}
