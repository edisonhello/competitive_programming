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
    for(;sq(a[mid].x-a[lll].x)<=sq_d && lll>=idl;--lll); ++lll;
    for(;sq(a[rrr].x-a[mid+1].x)<=sq_d && rrr<=idr;++rrr); --rrr;
    for(int i=lll;i<=rrr;++i)idx[i]=i;
    sort(idx+lll,idx+rrr+1,[](const int &x,const int &y){
        return a[x].y<a[y].y;
    });
    for(int i=lll;i<=rrr;++i){
        for(int j=i+1;j<=i+6 && j<=rrr;++j){
            ll td=dis(a[idx[i]],a[idx[j]]);
            int id1=a[idx[i]].id,id2=a[idx[j]].id;
            int mnid=min(id1,id2),mxid=max(id1,id2);
            tie(sq_d,mn_id1,mn_id2)=min(tie(sq_d,mn_id1,mn_id2),tie(td,mnid,mxid));
        }
    }
}

unordered_map<ll,vector<int>> ids;
#define get_id(x,y) ((1ll*(x)*1000000123+(y)))
void do_another(){
    vector<int> ans;
    int wid=(k+1)>>1;
    for(int i=0;i<n;++i){
        int blkx=a[i].x/wid,blky=a[i].y/wid;
        ids[get_id(blkx,blky)].push_back(i);
    }
    for(int i=0;i<n;++i){
        // cout<<"process "<<i<<endl;
        int ok=-1;
        int blkx=a[i].x/wid,blky=a[i].y/wid;
        for(int dx=-2;dx<=2;++dx){
            for(int dy=-2;dy<=2;++dy){
                int tx=blkx+dx,ty=blky+dy;
                ll numb=get_id(tx,ty);
                // cout<<"neightbor: "<<numb<<" ("<<tx<<","<<ty<<")"<<endl;
                auto it=ids.find(numb);
                if(it!=ids.end()){
                    for(int pid:it->second){
                        if(pid==i)continue;
                        if(dis(a[i],a[pid])<=k*1ll*k){
                            ok=pid;
                            break;
                        }
                    }
                    if(ok!=-1)break;
                }
            }
            if(ok!=-1)break;
        }
        // cout<<"ok: "<<ok<<endl;
        if(ok!=-1)ans.push_back(a[i].id);
        // cout<<i<<" push into "<<get_id(blkx,blky)<<endl;
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<" "; cout<<endl;
}
#undef get_id

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("in.txt","r",stdin);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i].id>>a[i].x>>a[i].y;
    }
    sq_d=dis(a[0],a[1]);
    mn_id1=min(a[0].id,a[1].id); mn_id1=max(a[0].id,a[1].id);

    sort(a,a+n,[](const flight &a,const flight &b){return a.x==b.x?a.y<b.y:a.x<b.x;});

    dc(0,n-1);
    cout<<mn_id1<<" "<<mn_id2<<" "<<sq_d<<endl;

    do_another();
}
