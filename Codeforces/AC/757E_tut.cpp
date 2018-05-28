#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> rec;

/* int solve(int r,int n){
    auto it=rec.find(make_pair(r,n));
    if(it!=rec.end())return it->second;
    if(r==0){
        int rt=0;
        for(int i=1;i<=n;++i){
            if(n%i==0 && __gcd(n/i,i)==1)++rt;
        }
        return rec[make_pair(r,n)]=rt;
    }
    else{
        int rt=0;
        for(int i=1;i<=n;++i){
            if(n%i==0)rt+=solve(r-1,i)+solve(r-1,n/i);
        }
        return rec[make_pair(r,n)]=rt/2;
    }
} */

const int mod=1000000007;

bitset<1000006> np;
vector<int> p;
int F[1000006][22];

inline int solve(int r,int n){
    int rt=1;
    for(int z:p){
        if(1ll*z*z>n)break;
        if(n%z)continue;
        int cnt=0;
        while(n%z==0)++cnt,n/=z;
        rt=1ll*rt*F[r][cnt]%mod;
    }
    return n>1?1ll*rt*F[r][1]%mod:rt;
}
void init(){
    for(int i=2;i<=1000000;++i){
        if(np[i])continue;
        p.push_back(i);
        for(long long j=1ll*i*i;j<=1000000;j+=i){
            np[j]=1;
        }
    }
    F[0][0]=1;
    for(int i=1;i<=20;++i)F[0][i]=2;
    for(int i=1,j;i<=1000000;++i){
        for(j=0;j<=20;++j){
            F[i][j]=((j?F[i][j-1]:0)+F[i-1][j])%mod;
        }
    }
}

int main(){
    /* for(int r=0;r<=20;++r){
        for(int i=1;i<=30;++i){
            printf("%4d ",solve(r,i));
        }
        cout<<endl;
    } */
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    int q; cin>>q; while(q--){
        int r,n; cin>>r>>n;
        cout<<solve(r,n)<<'\n';
    }
}
