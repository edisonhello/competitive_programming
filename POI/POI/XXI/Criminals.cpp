#include<bits/stdc++.h>
using namespace std;

int a[1000006],cs[1000006],ds[1000006],isc[1000006],isd[1000006],L[1000006],R[1000006],tmp[1000006],tmp2[1000006];

int main(){
    ios_base::sync_with_stdio(0);
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    int c,d; cin>>c>>d;
    for(int i=1;i<=c;++i)cin>>cs[i],isc[cs[i]]=i;
    for(int i=1;i<=d;++i)cin>>ds[i],isd[ds[i]]=i;
    for(int i=1;i<=n;++i){
        if(isc[a[i]]){
            if(isc[a[i]]==1){
                tmp[isc[a[i]]]=i;
                L[i]=i;
            }
            else{
                tmp[isc[a[i]]]=tmp[isc[a[i]]-1];
                L[i]=tmp[isc[a[i]]];
            }
        }
    }
    memset(tmp,0,sizeof(int)*(c+3));
    for(int i=n;i>=1;--i){
        if(isd[a[i]]){
            if(isd[a[i]]==1){
                tmp[isd[a[i]]]=i;
                R[i]=i;
            }
            else{
                tmp[isd[a[i]]]=tmp[isd[a[i]]-1];
                R[i]=tmp[isd[a[i]]];
            }
        }
    }
    memset(tmp,0,sizeof(int)*(d+3));
    int nl=1,nr=0,can=0;
    vector<int> ans;
    for(int i=1;i<=n;++i)++tmp2[a[i]];
    for(int i=1;i<=n;++i){
        if(a[i]==cs[c] && L[i] && R[i]){
            // cout<<i<<" "<<L[i]<<" "<<R[i]<<endl;
            while(nr<R[i]){
                ++nr;
                --tmp2[a[nr]];
                if(!tmp2[a[nr]] && tmp[a[nr]])--can;
            }
            while(nl<L[i]){
                ++tmp[a[nl]];
                if(tmp[a[nl]]==1 && tmp2[a[nl]])++can;
                ++nl;
            }
            if(can)ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<" "; cout<<endl;
}
