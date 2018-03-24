#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(x) ((x)*(x))

struct flight{
    ll x,y;
    int id;
} a[100005];


inline ll dis(const flight &a,const flight &b){
    return sq(a.y-b.y)+sq(a.x-b.x);
}

int n,idx[100005],mn_id1,mn_id2;
// int to_id[100005];
ll k,sq_d;

void dc(int idl,int idr){
    if(idl==idr)return;
    int mid=(idl+idr)>>1;
    dc(idl,mid);
    dc(mid+1,idr);
    int lll=mid,rrr=mid+1;
    for(;sq(a[mid].x-a[lll].x)<sq_d && lll>=idl;--lll); ++lll;
    for(;sq(a[rrr].x-a[mid+1].x)<sq_d && rrr<=idr;++rrr); --rrr;
    for(int i=lll;i<=rrr;++i)idx[i]=i;
//    sort(idx+lll,idx+rrr+1,[](const int &x,const int &y){
//        return a[x].y<a[y].y;
//    });
//    for(int i=lll;i<=rrr;++i){
//        for(int j=i+1;j<=i+6 && j<=rrr;++j){
//            ll td=dis(a[idx[i]],a[idx[j]]);
//            if(td<sq_d){
//                sq_d=td;
//                mn_id1=idx[i];
//                mn_id2=idx[j];
//            }
//        }
//    }
    for(int i=lll;i<=rrr;++i){
        for(int j=i+1;j<=rrr;++j){
            ll td=dis(a[idx[i]],a[idx[j]]);
            if(td<sq_d){
                sq_d=td;
                mn_id1=idx[i];
                mn_id2=idx[j];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i].id>>a[i].x>>a[i].y;
    }
    sq_d=dis(a[0],a[1]); mn_id1=0; mn_id1=1;
    sort(a,a+n,[](const flight &a,const flight &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    dc(0,n-1);
    cout<<a[mn_id1].id<<" "<<a[mn_id2].id<<" "<<sq_d<<endl;
}
