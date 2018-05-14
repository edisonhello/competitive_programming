#include<bits/stdc++.h>
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,tune=native")
using namespace std;
#define time iooiioioioio
#define MAX 100000000
#define DEBUG 1

multiset<int> pos[300005];
map<pair<int,int>,int> end_time;

struct E{
    int time,pos,type,oc,match_endtime;
};
vector<E> es;
struct Q{
    int pos,time,id;
};
vector<Q> qs;

int ans[300005],cnt_type;

void do_event(E e){
//    cout<<"processing event: "<<e.time<<" "<<e.pos<<" "<<e.type<<" "<<e.oc<<endl;
    if(e.oc==1){
        auto &edtime=end_time[make_pair(e.type,e.pos)];
        if(edtime!=0 && edtime>=e.time){
            edtime=max(edtime,e.match_endtime);
            return;
        }
        else edtime=e.match_endtime;
        if(pos[e.type].empty())++cnt_type;
        pos[e.type].insert(e.pos);
    }
    else{
        auto &edtime=end_time[make_pair(e.type,e.pos)];
        if((edtime!=0 && edtime>e.time) || edtime==-100){
            return;
        }
        else edtime=-100;
        pos[e.type].erase(pos[e.type].find(e.pos));
        if(pos[e.type].empty())--cnt_type;
    }
}
int getans(int p,int k){
    int ans=0;
    for(int i=1;i<=k;++i){
        auto it=pos[i].lower_bound(p);
//        if(*it==p)continue;
        int mn=1<<30;
        if(it!=pos[i].begin()){
            --it;
            mn=min(mn,p-*it);
            ++it;
        }
        if(it!=pos[i].end()){
            mn=min(mn,*it-p);
        }
        ans=max(ans,mn);
    }
    return ans;
}

//#define getchar getchar_unlocked
int rit(){
    int x=0; char c;
    while((c=getchar()) && (c<'0' || c>'9'));
    do{ x=x*10+(c&15); c=getchar();}while(c>='0' && c<='9');
    return x;
}

int main(){
//    freopen("in.txt","r",stdin);
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int n=rit(),k=rit(),qc=rit();
    E e;
    for(int i=0;i<n;++i){
        int x=rit(),t=rit(),a=rit(),b=rit();
        e.time=a; e.pos=x; e.type=t; e.oc=1; e.match_endtime=b+1;
        es.push_back(e);
        e.time=b+1; e.pos=x; e.type=t; e.oc=-1;
        es.push_back(e);
    }
    Q q;
    for(int i=0;i<qc;++i){
        int l=rit(),y=rit();
        q.pos=l; q.time=y; q.id=i;
        qs.push_back(q);
    }
    sort(es.begin(),es.end(),[&](const E &a,const E &b){return a.time<b.time;});
    sort(qs.begin(),qs.end(),[&](const Q &a,const Q &b){return a.time<b.time;});
    vector<E>::iterator it=es.begin();
    for(Q &q:qs){
        while(it!=es.end() && it->time<=q.time)do_event(*it),++it;
        if(cnt_type<k)ans[q.id]=-1;
        else ans[q.id]=getans(q.pos,k);
    }
    for(int i=0;i<qc;++i)printf("%d\n",ans[i]);
}




