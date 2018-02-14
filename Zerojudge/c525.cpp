#include<bits/stdc++.h>
using namespace std;
#define ld long double

ld x[28],y[28],d[28];

inline ld dis(int i,int j){
    return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--){
        int n; cin>>n;
        for(int i=0;i<n;++i)cin>>x[i]>>y[i];
        int perm[28];
        for(int i=0;i<n;++i)perm[i]=i;
        ld ans=1e20;
        do{
            ld now=0;
            for(int i=1;i<n;++i)now+=dis(perm[i],perm[i-1]);
            ans=min(ans,now);
        }while(next_permutation(perm,perm+n));
        cout<<fixed<<setprecision(2)<<ans<<'\n';
    }
}
