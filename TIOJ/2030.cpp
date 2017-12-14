#include<bits/stdc++.h>
using namespace std;
#define ll long long

int blocksize=1;

struct modify{
    int t,x,y,z;
    modify(int t=0,int x=0,int y=0,int z=0):t(t),x(x),y(y),z(z){}
} mod[100005];
struct query{
    int l,r,lb,rb,t,i;
    query(int t=0,int l=0,int r=0,int i=0):l(l),r(r),lb(l/blocksize),rb(r/blocksize),t(t),i(i){}
} que[100005];

ll nowans,ans[100005];
int a[100005],insegment[100005],T=0,L=1,R=0;
pair<int,int> lazerinfo[100005],another[100005],*isleft;
set<int> isright[100005];

void domodify(int t){
    if(mod[t].t==1){
        swap(a[mod[t].x],mod[t].y);
        if(L<=mod[t].x && mod[t].x<=R){
            --insegment[mod[t].y];
            if(!insegment[mod[t].y])nowans-=mod[t].y;
            if(!insegment[a[mod[t].x]])nowans+=a[mod[t].x];
            ++insegment[a[mod[t].x]];
        }
    }
    else{
        int l=mod[t].x,r=mod[t].y,v=mod[t].z;
        if(isleft[l].first==0){
            isleft[l]={r,v};
            isright[r].insert(l);
            if(L<=l && r<=R)nowans+=v;
        }
        else{
            isleft[l]={0,0};
            isright[r].erase(l);
            if(L<=l && r<=R)nowans-=v;
        }
    }
}
void addR(int x){
    if(!insegment[a[x]])nowans+=a[x];
    ++insegment[a[x]];
    for(int i:isright[x]){
        if(i>=L)nowans+=isleft[i].second;
    }
}
void subR(int x){
    --insegment[a[x]];
    if(!insegment[a[x]])nowans-=a[x];
    for(int i:isright[x]){
        if(i>=L)nowans-=isleft[i].second;
    }
}
void addL(int x){
    if(!insegment[a[x]])nowans+=a[x];
    ++insegment[a[x]];
    if(lazerinfo[x].first<=R)nowans+=lazerinfo[x].second;
}
void subL(int x){
    --insegment[a[x]];
    if(!insegment[a[x]])nowans-=a[x];
    if(lazerinfo[x].first<=R)nowans-=lazerinfo[x].second;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    blocksize=ceil(pow(n,2./3));
    int countmodify=0,querynumber=0;
    isleft=lazerinfo;
    while(q--){
        int type,x,y,z; cin>>type;
        if(type==1)cin>>x>>y,mod[countmodify]=modify(1,x,y),++countmodify;
        if(type==2)cin>>x>>y>>z,mod[countmodify]=modify(2,x,y,z),lazerinfo[x]={y,z},++countmodify;
        if(type==3)cin>>x,mod[countmodify]=modify(2,x,lazerinfo[x].first,lazerinfo[x].second),++countmodify;
        if(type==4)cin>>x>>y,que[querynumber]=query(countmodify,x,y,querynumber),++querynumber;
    }
    sort(que,que+querynumber,[](const query &a,const query &b){return a.lb==b.lb?a.rb==a.rb?a.t<b.t:a.rb<b.rb:a.lb<b.lb;});
    memset(lazerinfo,0,sizeof(lazerinfo));
    for(int i=0;i<querynumber;++i){
        while(que[i].t>T)domodify(T),++T;
        while(que[i].t<T)domodify(--T);
        while(R<que[i].r)addR(++R);
        while(L>que[i].l)addL(--L);
        while(R>que[i].r)subR(R),--R;
        while(L<que[i].l)subL(L),++L;
        ans[que[i].i]=nowans;
    }
    for(int i=0;i<querynumber;++i)cout<<ans[i]<<'\n';
}
