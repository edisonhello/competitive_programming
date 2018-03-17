/*
given 505*505 grid with number, and 1e4 queries
for each query (l,r) find a largest square in grid st
the max number in square <= r and
the min number in square >= l
*/

#include<bits/stdc++.h>
using namespace std;

int n,m,lg2[505],ans[10004];
int h[505][505],mnspa[505][10][505],mxspa[505][10][505],_mnspa[10][505][505],_mxspa[10][505][505],mn[505][505][505],mx[505][505][505];

struct Q{
    int lb,ub,i;
};

void solve(int l,int r,vector<Q> &qs){
    if(l>r)return;
    if(qs.empty())return;
    int mid=((l+r+1)>>1);
    // cout<<"solve "<<l<<" "<<r<<" : "<<mid<<endl;
    vector<pair<int,int>> segs;
    for(int i=1;i+mid-1<=n;++i){
        for(int j=1;j+mid-1<=m;++j){
            segs.emplace_back(mn[i][j][mid],mx[i][j][mid]);
        }
    }
    sort(segs.begin(),segs.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.second<b.second;});
    // for(auto i:segs)cout<<"("<<i.first<<" "<<i.second<<")"; cout<<endl;
    vector<Q> le,ri;
    int ptr=0,lb=0;
    for(Q &q:qs){
        while(ptr<segs.size() && segs[ptr].second<=q.ub)lb=max(lb,segs[ptr].first),++ptr;
        // cout<<"q: "<<q.lb<<" "<<q.ub<<" nlb: "<<lb<<endl;
        if(lb>=q.lb){
            ans[q.i]=mid;
            ri.push_back(q);
        }
        else le.push_back(q);
    }
    solve(l,mid-1,le);
    solve(mid+1,r,ri);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i<505;++i)lg2[i]=lg2[i>>1]+1;
    while(cin>>n>>m,n){
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>h[i][j];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j)mnspa[i][0][j]=mxspa[i][0][j]=h[i][j];
            for(int z=1,d=1;d<m;++z,d<<=1){
                for(int j=1;j+d<=m;++j){
                    mxspa[i][z][j]=max(mxspa[i][z-1][j],mxspa[i][z-1][j+d]);
                    mnspa[i][z][j]=min(mnspa[i][z-1][j],mnspa[i][z-1][j+d]);
                }
            }
        }
        for(int j=1;j<=m;++j){
            for(int i=1;i<=n;++i)_mxspa[0][i][j]=_mnspa[0][i][j]=h[i][j];
            for(int z=1,d=1;d<n;++z,d<<=1){
                for(int i=1;i+d<=n;++i){
                    _mxspa[z][i][j]=max(_mxspa[z-1][i][j],_mxspa[z-1][i+d][j]);
                    _mnspa[z][i][j]=min(_mnspa[z-1][i][j],_mnspa[z-1][i+d][j]);
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                int nmn=h[i][j],nmx=h[i][j];
                mn[i][j][1]=mx[i][j][1]=h[i][j];
                for(int len=2;i+len-1<=n && j+len-1<=m;++len){
                    int z=lg2[len];
                    nmn=min(nmn,min(mnspa[i+len-1][z][j],mnspa[i+len-1][z][j+len-(1<<z)]));
                    // cout<<"tmp "<<nmn<<" "<<mnspa[i+len-1][z][j]<<" "<<mnspa[i+len-1][z][j+len-(1<<z)]<<endl;
                    nmn=min(nmn,min(_mnspa[z][i][j+len-1],_mnspa[z][i+len-(1<<z)][j+len-1]));
                    nmx=max(nmx,max(mxspa[i+len-1][z][j],mxspa[i+len-1][z][j+len-(1<<z)]));
                    nmx=max(nmx,max(_mxspa[z][i][j+len-1],_mxspa[z][i+len-(1<<z)][j+len-1]));
                    mn[i][j][len]=nmn, mx[i][j][len]=nmx;
                    // cout<<i<<" "<<j<<" "<<len<<" "<<mn[i][j][len]<<" "<<mx[i][j][len]<<endl;
                }
            }
        }
        int q,lb,ub; cin>>q; 
        vector<Q> qs(q);
        for(int i=0;i<q;++i){
            cin>>lb>>ub;
            qs[i]={lb,ub,i};
        }
        sort(qs.begin(),qs.end(),[](const Q &a,const Q &b){return a.ub<b.ub;});
        solve(1,min(n,m),qs);
        for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
        cout<<"-\n";
    }
}
