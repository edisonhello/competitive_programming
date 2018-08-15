#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,sse,sse2,sse3,ssse3,tune=native")
using namespace std;
#define ll long long

const ll mod=1e9+7;

int a[11111];
int rec[10002][10002];



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l; cin>>n>>l;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(n<=2000)for(int i=1;i<=n-l+1;++i){
        int cnt=0;
        for(int j=1;j<=n-l+1;++j){
            int diff=0;
            int c0=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0;
            int bg=l>>3,sm=l&7;
            int *aa=a+i,*ab=a+j;
            while(sm--)diff+=(*(aa++))==((*ab++));
            while(bg--){
                c0+=(*(aa++))==(*(ab++));
                c1+=(*(aa++))==(*(ab++));
                c2+=(*(aa++))==(*(ab++));
                c3+=(*(aa++))==(*(ab++));
                c4+=(*(aa++))==(*(ab++));
                c5+=(*(aa++))==(*(ab++));
                c6+=(*(aa++))==(*(ab++));
                c7+=(*(aa++))==(*(ab++));
            }
            // cout<<i<<" "<<j<<" "<<diff+c0+c1+c2+c3+c4+c5+c6+c7<<endl;
            for(int z=0;z<=l;++z)if(l-(diff+c0+c1+c2+c3+c4+c5+c6+c7)<=z)++rec[i][z];
        }
        // cout<<cnt-1<<" ";
    }
    int q; cin>>q; while(q--){
        int tar; cin>>tar;
        if(tar==0){
            vector<ll> pp(n+1),hh(n+1);
            pp[0]=1;
            for(int i=1;i<=n;++i)pp[i]=pp[i-1]*7122%mod;
            for(int i=1;i<=n;++i)hh[i]=(hh[i-1]+pp[i]*a[i])%mod;
            // map<int,int> mp;
            // for(int i=1;i<=n;++i
            for(int i=1;i<=n-l+1;++i){
                int c=-1;
#define ghh(l,r) ((hh[r]-hh[l-1]+mod)%mod*pp[n-l]%mod)
                for(int j=1;j<=n-l+1;++j){
                    if(ghh(i,i+l-1)==ghh(j,j+l-1))++c;
                }
                cout<<c<<' ';
            }
            cout<<'\n';
            continue;
        }
        for(int i=1;i<=n-l+1;++i)cout<<rec[i][tar]-1<<' ';
        cout<<'\n';
    }
}
