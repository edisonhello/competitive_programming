#include<bits/stdc++.h>
using namespace std;

int a[2005],b[2005],bitx[2005][2005],bity[2005][2005];

int query(int *bit,int x,int v=0){
    for(;x;x-=x&-x)v=max(v,bit[x]);
    return v;
}
void add(int *bit,int x,int v){
    for(;x<2005;x+=x&-x)bit[x]=max(bit[x],v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--){
        memset(bitx,0,sizeof(bitx));
        memset(bity,0,sizeof(bity));
        int n; cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
        sort(b+1,b+1+n);
        int m=unique(b+1,b+1+n)-b;
        for(int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+1+m,a[i])-b+1; m+=2;
        // for(int i=1;i<=n;++i)cout<<a[i]<<" "; cout<<endl;
        int ans=0;
        for(int i=1;i<=n;++i){
            // cout<<"i="<<i<<endl;
            vector<tuple<int,int,int>> upl;
            for(int j=1;j<=m;++j){
                upl.emplace_back(a[i],j,query(bity[j],a[i]-1)+1);
                upl.emplace_back(j,a[i],query(bitx[j],a[i]-1)+1);
            }
            for(auto &tu:upl){
                // cout<<get<0>(tu)<<","<<get<1>(tu)<<" update with "<<get<2>(tu)<<endl;
                add(bitx[get<0>(tu)],get<1>(tu),get<2>(tu));
                add(bity[get<1>(tu)],get<0>(tu),get<2>(tu));
                ans=max(ans,get<2>(tu));
            }
        }
        cout<<ans<<endl;
    }
}
