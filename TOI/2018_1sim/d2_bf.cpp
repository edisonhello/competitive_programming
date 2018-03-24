
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


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in.txt","r",stdin);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i].id>>a[i].x>>a[i].y;
    }
    sq_d=dis(a[0],a[1]); mn_id1=0; mn_id1=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<i;++j){
            if(dis(a[i],a[j])<sq_d){
                sq_d=dis(a[i],a[j]);
                mn_id1=min(a[i].id,a[j].id);
                mn_id2=max(a[i].id,a[j].id);
            }
            else if(dis(a[i],a[j])==sq_d){
                int tmn_id1=min(a[i].id,a[j].id),tmn_id2=max(a[i].id,a[j].id);
                tie(mn_id1,mn_id2)=min(make_pair(mn_id1,mn_id2),make_pair(tmn_id1,tmn_id2));
            }
        }
    }
    cout<<mn_id1<<" "<<mn_id2<<" "<<sq_d<<endl;
}
