#include<bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int xm,ym,zm; cin>>xm>>ym>>zm;
    int n,m,k; cin>>n>>m>>k;
    int mxl=xm,mxr=1,myl=ym,myr=1,mzl=zm,mzr=1;
    for(int i=1;i<=n;++i){
        int x,y,z; cin>>x>>y>>z;
        mxl=min(mxl,x); mxr=max(mxr,x);
        myl=min(myl,y); myr=max(myr,y);
        mzl=min(mzl,z); mzr=max(mzr,z);
    }
    int nxl=1,nxr=xm,nly=1,nyr=ym,nzl=1,nzr=zm;
    for(int i=1;i<=m;++i){
        int x,y,z; cin>>x>>y>>z;

    }
}
