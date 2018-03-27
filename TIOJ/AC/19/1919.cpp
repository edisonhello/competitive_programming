#include<bits/stdc++.h>
using namespace std;
#define lb(x) ((x)&-(x))

struct M{
    int l,r,c,i;
}; // this is a picture
vector<M> ms;
struct Q{
    int l,r,i,sgn;
}; // this is a person
vector<Q> qs;

int a[100005],ans[100005];
// ,prvapp[100005],nxtapp[100005];
vector<int> app[100005];
long long v[100005],change[100005];
long long bit[100005];

void add(int x,int v){
    // cout<<"add "<<v<<" at "<<x<<endl;
    for(;x<100005;x+=lb(x))bit[x]+=v;
}
long long query(int x,long long v=0){
    // cout<<"query prefix "<<x<<" get ";
    for(;x;x-=lb(x))v+=bit[x];
    // cout<<v<<endl;
    return v;
}

void bns(int l,int r,vector<int> &pp){
    // cout<<"bns "<<l<<" "<<r<<endl;
    if(l>r || pp.empty())return;
    int mid=(l+r)>>1;
    vector<int> mids;
    for(int i=l;i<=mid;++i)mids.push_back(i);
    sort(mids.begin(),mids.end(),[&](const int &a,const int &b){return ms[a].r<ms[b].r;});

    qs.clear();
    for(int i:pp){
        for(int j=1;j<app[i].size();++j){
            if(app[i][j-1]+1>app[i][j]-1)continue;
            qs.push_back({app[i][j-1]+1,app[i][j]-1,i,-1});
        }
        change[i]=0;
    }
    // for(Q q:qs)cout<<"["<<q.l<<" , "<<q.r<<" ] : "<<q.i<<" * "<<q.sgn<<endl;
    sort(qs.begin(),qs.end(),[](const Q &a,const Q &b){return a.r<b.r;});

    int qptr=0;
    long long rec=0;
    for(int mid:mids){
        M &m=ms[mid];
        while(qptr<qs.size() && qs[qptr].r<m.r){
            change[qs[qptr].i]-=rec-query(qs[qptr].l-1);
            // cout<<"run "<<"["<<qs[qptr].l<<" , "<<qs[qptr].r<<" ] : "<<qs[qptr].i<<" * "<<qs[qptr].sgn<<" , get "<<rec-query(qs[qptr].l-1)<<endl;
            ++qptr;
        }
        rec+=m.c;
        add(m.l,m.c);
        /* while(qptr<qs.size() && qs[qptr].r<=m.r){
            change[qs[qptr].i]-=rec-query(qs[qptr].l-1);
            cout<<"run "<<"["<<qs[qptr].l<<" , "<<qs[qptr].r<<" ] : "<<qs[qptr].i<<" * "<<qs[qptr].sgn<<" , query "<<query(qs[qptr].l-1)<<" get "<<rec-query(qs[qptr].l-1)<<endl;
            ++qptr;
        } */
    }
    while(qptr<qs.size()){
        change[qs[qptr].i]-=rec-query(qs[qptr].l-1);
        ++qptr;
    }

    qs.clear();

    for(int i:pp)change[i]+=rec;
    for(int mid:mids)add(ms[mid].l,-ms[mid].c);

    mids.clear();

    vector<int> lp,rp;
    for(int i:pp){
        // cout<<"for people "<<i<<" change "<<change[i]<<" need "<<v[i]<<endl;
        if(change[i]>=v[i]){
            ans[i]=mid;
            lp.push_back(i);
        }
        else{
            v[i]-=change[i];
            rp.push_back(i);
        }
    }

    if(l==r)return;
    mids.clear(); pp.clear();
    mids.reserve(0); pp.reserve(0);
    bns(l,mid,lp); bns(mid+1,r,rp);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q; cin>>n>>m>>q;
    for(int i=1;i<=n;++i)app[i].push_back(0);
    for(int i=1,t;i<=m;++i){
        cin>>t;
        // prvapp[i]=app[a[i]].back();
        // nxtapp[app[a[i]].back()]=i;
        app[t].push_back(i);
    }
    for(int i=1;i<=n;++i)/* nxtapp[app[i].back()]=m+1, */app[i].push_back(m+1);

    for(int i=1;i<=n;++i)cin>>v[i];
    for(int i=0;i<q;++i){
        int l,r,c; cin>>l>>r>>c;
        ms.push_back({l,r,c,i});
    }
    memset(ans,-1,sizeof(ans));
    vector<int> pp;
    for(int i=1;i<=n;++i)pp.push_back(i);
    /* for(int i=1;i<=n;++i){
        for(int x:app[i]){
            qs.push_back({1,nxtapp[x]?:n,i,1});
            qs.push_back({1,x-1,i,-1});
            qs.push_back({x+1,nxtapp[x]?:n,i,-1});
        }
    }
    cout<<"all qs: "<<endl;
    for(Q q:qs)cout<<"["<<q.l<<" , "<<q.r<<" ] : "<<q.i<<" * "<<q.sgn<<endl; */
    bns(0,q-1,pp);
    for(int i=1;i<=n;++i)cout<<(ans[i]==-1?-1:ans[i]+1)<<'\n';
}
