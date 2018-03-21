#include<bits/stdc++.h>
using namespace std;
#define ll long long

// #include"/home/edison/Coding/cpp/template/debug.cpp"
#define PDE(...) ;


int n;
ll d[500005],moved[500005];


int pos(int t,int w){
    return -w+(t/moved[w]*d[w]);
}
int get(int t,int x){
    PDE(t,x);
    int L=0,R=n+1;
    while(R>L){
        int m=(L+R)>>1;
        PDE(m,pos(t,m));
        if(pos(t,m)>x)L=m+1;
        else R=m;
    }
    PDE(L);
    return L;
}
int solve(int t,int l,int r){
    // PDE(t,l,r,get(t,r),get(t,l));
    return -(get(t,r)-get(t,l-1));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin>>n>>q;
    d[0]=moved[0]=1;
    for(int i=1;i<=n;++i)cin>>d[i];
    for(int i=2;i<=n;++i)d[i]=max(d[i],d[i-1]);
    moved[1]=d[1];
    for(int i=2;i<=n;++i){
        d[i]=(d[i]-1)/d[i-1]+1;
        moved[i]=moved[i-1]*d[i];
        d[i]*=d[i-1];
    }
    // for(int i=1;i<=n;++i)cout<<i<<" "<<d[i]<<" "<<moved[i]<<endl;
    while(q--){
        int t,l,r; cin>>t>>l>>r;
        cout<<solve(t,l,r)<<endl;
    }
}
/*  tutorial by waynetu */
// one submit AC
