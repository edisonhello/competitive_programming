#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair

int R[300007],G[300007],B[300007];
int r,g,b;
int connect[300007];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int p; char type; cin>>p>>type;
        if(type=='R')R[r++]=p;
        else if(type=='G')G[g++]=p;
        else B[b++]=p;
    }
    if(!g){
        ll ans=0;
        for(int i=1;i<r;++i)ans+=R[i]-R[i-1];
        for(int j=1;j<b;++j)ans+=B[j]-B[j-1];
        cout<<ans<<endl;
        exit(0);
    }
    ll ans=0;
    if(r && R[0]<G[0])ans+=G[0]-R[0];
    if(r && R[r-1]>G[g-1])ans+=R[r-1]-G[g-1];
    if(b && B[0]<G[0])ans+=G[0]-B[0];
    if(b && B[b-1]>G[g-1])ans+=B[b-1]-G[g-1];
    for(int i=1;i<g;++i){
        auto it1=lower_bound(B,B+b,G[i-1]),it2=lower_bound(B,B+b,G[i]);
        int case1=G[i]-G[i-1],case2=2*(G[i]-G[i-1]);
        vector<int> itv;
        vector<int> segs;
        segs.push_back(G[i-1]);
        while(it1!=it2)segs.push_back(*it1),++it1;
        segs.push_back(G[i]);
        for(int i=1;i<segs.size();++i)itv.push_back(segs[i]-segs[i-1]);
        sort(itv.begin(),itv.end());
        for(int i=0;i<itv.size()-1;++i)case1+=itv[i];
        itv.clear();
        segs.clear();
        it1=lower_bound(R,R+r,G[i-1]),it2=lower_bound(R,R+r,G[i]);
        segs.push_back(G[i-1]);
        while(it1!=it2)segs.push_back(*it1),++it1;
        segs.push_back(G[i]);
        for(int i=1;i<segs.size();++i)itv.push_back(segs[i]-segs[i-1]);
        sort(itv.begin(),itv.end());
        for(int i=0;i<itv.size()-1;++i)case1+=itv[i];
        ans+=min(case1,case2);
    }

    cout<<ans<<endl;
}
