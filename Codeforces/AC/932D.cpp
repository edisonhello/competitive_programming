#pragma GCC optimize("no-stack-protector")
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    pair<int,pair<ll,ll>> con[20];
    pair<int,ll> mx[20];
    ll w;
    int dep;
    node(){
        memset(con,0,sizeof(con));
        memset(mx,0,sizeof(mx));
        w=0;
        dep=0;
    }
} pool[400009],*pos[400009];

int ans;

void build(node *now,int pa,ll wei){
    now->dep=pos[pa]->dep+1;
    now->w=wei;
    now->mx[0]=make_pair(pa,wei);
    for(int i=1;i<20;++i){
        if(pos[now->mx[i-1].first]->mx[i-1].first==0)break;
        now->mx[i].first=pos[now->mx[i-1].first]->mx[i-1].first;
        now->mx[i].second=max(now->mx[i-1].second,pos[now->mx[i-1].first]->mx[i-1].second);
    }
    node *climb=pos[pa];
    int climbid=pa;
    for(int i=19;i>=0;--i){
        if(!climb->mx[i].first)continue;
        if(climb->mx[i].second>=now->w)continue;
        climbid=climb->mx[i].first;
        climb=pos[climb->mx[i].first];
    }
    if(climb->w>=now->w){
        // cout<<"new node's climb[0] id is "<<climbid<<endl;
        now->con[0]=make_pair(climbid,make_pair(now->w,now->w));
        for(int i=1;i<20;++i){
            if(!now->con[i-1].first)break;
            now->con[i].first=pos[now->con[i-1].first]->con[i-1].first;
            now->con[i].second.first=now->con[i-1].second.first+pos[now->con[i-1].first]->con[i-1].second.first;
            now->con[i].second.second=max(now->con[i-1].second.second,pos[now->con[i-1].first]->con[i-1].second.second);
        }
    }
}

// ll wleft;
void query(node *now,ll wmax,ll prv){
    for(int i=19;i>=0;--i){
        if(now->con[i].first && now->con[i].second.first<=wmax){
            ans+=1<<i;
            // cout<<"climb i="<<i<<", new node id: "<<now->con[i].first<<endl;
            query(pos[now->con[i].first],wmax-now->con[i].second.first,max(prv,now->con[i].second.second));
            return;
        }
    }
    // wleft=wmax;
    if(now->w>=prv && wmax>=now->w)++ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int lastans=0,idx=2;
    pos[1]=&pool[1];
    int q; cin>>q; while(q--){
        int c; ll p,q; cin>>c>>p>>q;
        p^=lastans; q^=lastans;
        // cout<<"p: "<<p<<" , q: "<<q<<endl;
        if(c==1){
            pos[idx]=&pool[idx];
            build(pos[idx],p,q);
            ++idx;
        }
        else{
            ans=0;
            query(pos[p],q,-1234);
            // if(ans==pos[p]->dep && wleft==q)++ans;
            cout<<ans<<'\n';
            lastans=ans;
        }
    }
}
