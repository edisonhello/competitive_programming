#include<bits/stdc++.h>
using namespace std;
#define time iooiioioioio
#define MAX 100000000
#define DEBUG 1

struct func{
    int a,b,tt;
    func(int a,int b,int tt):a(a),b(b),tt(tt){}
    int get(int x)const{return a*x+b;}
};

int now_ref_point;
bool comp(const func &a,const func &b){
    return make_tuple(a.get(now_ref_point),a.a,a.b,a.tt)>make_tuple(b.get(now_ref_point),b.a,b.b,b.tt);
}

struct node{
    node *l,*r;
    int ref_point;
    multiset<func,decltype(&comp)> funcs{comp};
    node():l(0),r(0),ref_point(0){}
} *root;
node *getnode(){
    return new node();
}

#define mid ((l+r)>>1)
void add_func(node *&now,int l,int r,int ml,int mr,func &ref_func){
    if(r<ml || mr<l)return;
    if(!now)now=getnode();
//    cout<<"in add func "<<l<<" to "<<r<<", address "<<now<<endl;
    if(l==r){
        now_ref_point=l;
        now->funcs.insert(ref_func);
//        if(l==1 && r==1)cout<<"this is a [1,1], size: "<<now->funcs.size()<<endl;
        return;
    }
    if(ml<=l&&r<=mr){
        int d1,d2;
        now_ref_point=l;
        now->funcs.insert(ref_func);
        d1=distance(now->funcs.begin(),now->funcs.find(ref_func));
        now->funcs.erase(now->funcs.find(ref_func));
        now_ref_point=r;
        now->funcs.insert(ref_func);
        d2=distance(now->funcs.begin(),now->funcs.find(ref_func));
        if(d1!=d2){
            now->funcs.erase(ref_func);
            add_func(now->l,l,mid,ml,mr,ref_func);
            add_func(now->r,mid+1,r,ml,mr,ref_func);
        }
        else;
        return;
    }
    add_func(now->l,l,mid,ml,mr,ref_func);
    add_func(now->r,mid+1,r,ml,mr,ref_func);
}
void remove_func(node *&now,int l,int r,int ml,int mr,func &ref_func){
    if(r<ml || mr<l)return;
//    cout<<"in remove func "<<l<<" to "<<r<<", address "<<now<<endl;
//    assert(now);
    if(ml<=l&&r<=mr){
        now_ref_point=l;
        auto it=now->funcs.find(ref_func);
        if(it!=now->funcs.end()){
            now->funcs.erase(it);
            return;
        }
        else{
            if(l==r)assert(0);
            remove_func(now->l,l,mid,ml,mr,ref_func);
            remove_func(now->r,mid+1,r,ml,mr,ref_func);
            return;
        }
    }
    remove_func(now->l,l,mid,ml,mr,ref_func);
    remove_func(now->r,mid+1,r,ml,mr,ref_func);
}
int query(node *now,int l,int r,int x){
    if(!now)return 0;
    if(x<l || r<x)return 0;
    int rt=0;
    if(x<=mid)rt=max(rt,query(now->l,l,mid,x));
    else rt=max(rt,query(now->r,mid+1,r,x));
    if(now->funcs.size())rt=max(rt,now->funcs.begin()->get(x));
    return rt;
}
#undef mid

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
//    if(DEBUG)cout<<"processing event: "<<e.time<<" "<<e.pos<<" "<<e.type<<" "<<e.oc<<endl;
    if(e.oc==1){
        auto &edtime=end_time[make_pair(e.type,e.pos)];
        if(edtime!=0 && edtime>=e.time){
            edtime=max(edtime,e.match_endtime);
//            cout<<"skip this add "<<endl;
            return;
        }
        else edtime=e.match_endtime;
        if(pos[e.type].empty())++cnt_type;
        auto it=pos[e.type].lower_bound(e.pos);
//        assert(pos[e.type].find(e.pos)==pos[e.type].end());
        if(it!=pos[e.type].begin()){
            if(it!=pos[e.type].end()){
                int nxpos=*it; --it;
                int pvpos=*it; ++it;
                int mid=(nxpos+pvpos)>>1;
                func ref_func(1,-pvpos,e.type);
                remove_func(root,1,MAX,pvpos,mid,ref_func);
            }
            else{
                --it;
                int pvpos=*it; ++it;
                func ref_func(1,-pvpos,e.type);
//                cout<<"call remove func "<<pvpos<<" to "<<MAX<<endl;
                remove_func(root,1,MAX,pvpos,MAX,ref_func);
            }
        }
        if(it!=pos[e.type].end()){
            if(it!=pos[e.type].begin()){
                int nxpos=*it; --it;
                int pvpos=*it; ++it;
                int mid=(nxpos+pvpos)>>1;
                func ref_func(-1,nxpos,e.type);
                remove_func(root,1,MAX,mid+1,nxpos,ref_func);
            }
            else{
                int nxpos=*it;
                func ref_func(-1,nxpos,e.type);
                remove_func(root,1,MAX,1,nxpos,ref_func);
            }
        }
//        cout<<"removed old segments"<<endl;
        pos[e.type].insert(e.pos);
        it=pos[e.type].find(e.pos);
        if(it!=pos[e.type].begin()){
            --it;
            int pvpos=*it; ++it;
            int mid=(pvpos+e.pos)>>1;
            func ref_func(1,-pvpos,e.type);
            add_func(root,1,MAX,pvpos,mid,ref_func);
            ref_func=func(-1,e.pos,e.type);
            add_func(root,1,MAX,mid+1,e.pos,ref_func);
        }
        else{
            func ref_func(-1,e.pos,e.type);
//            cout<<"call add func "<<1<<" to "<<e.pos<<" , add "<<ref_func.a<<";"<<ref_func.b<<endl;
            add_func(root,1,MAX,1,e.pos,ref_func);
//            cout<<"called finished"<<endl;
        }
        if(it!=--pos[e.type].end()){
            ++it;
            int nxpos=*it; --it;
            int mid=(e.pos+nxpos)>>1;
            func ref_func(1,-e.pos,e.type);
            add_func(root,1,MAX,e.pos,mid,ref_func);
            ref_func=func(-1,nxpos,e.type);
            add_func(root,1,MAX,mid+1,nxpos,ref_func);
        }
        else{
            func ref_func(1,-e.pos,e.type);
//            cout<<"call add func "<<e.pos<<" to "<<MAX<<" , add "<<ref_func.a<<";"<<ref_func.b<<endl;
            add_func(root,1,MAX,e.pos,MAX,ref_func);
//            cout<<"called finished"<<endl;
        }
    }
    else{
        auto &edtime=end_time[make_pair(e.type,e.pos)];
        if((edtime!=0 && edtime>e.time) || edtime==-100){
//            cout<<"skip this erase"<<endl;
            return;
        }
        else{
            edtime=-100;
        }
        auto it=pos[e.type].find(e.pos);
        if(it!=pos[e.type].begin()){
            --it;
            int pvpos=*it; ++it;
            int mid=(pvpos+e.pos)>>1;
            func ref_func(1,-pvpos,e.type);
            remove_func(root,1,MAX,pvpos,mid,ref_func);
            ref_func=func(-1,e.pos,e.type);
            remove_func(root,1,MAX,mid+1,e.pos,ref_func);
        }
        else{
            func ref_func(-1,e.pos,e.type);
//            cout<<"call remove func "<<1<<" to "<<e.pos<<" , remove "<<ref_func.a<<";"<<ref_func.b<<endl;
            remove_func(root,1,MAX,1,e.pos,ref_func);
//            cout<<"called finished"<<endl;
        }
        if(it!=--pos[e.type].end()){
            ++it;
            int nxpos=*it; --it;
            int mid=(e.pos+nxpos)>>1;
            func ref_func(1,-e.pos,e.type);
            remove_func(root,1,MAX,e.pos,mid,ref_func);
            ref_func=func(-1,nxpos,e.type);
            remove_func(root,1,MAX,mid+1,nxpos,ref_func);
        }
        else{
            func ref_func(1,-e.pos,e.type);
//            cout<<"call remove func "<<e.pos<<" to "<<MAX<<" , remove "<<ref_func.a<<";"<<ref_func.b<<endl;
            remove_func(root,1,MAX,e.pos,MAX,ref_func);
//            cout<<"called finished"<<endl;
        }
        pos[e.type].erase(e.pos);
        it=pos[e.type].lower_bound(e.pos);
        if(it!=pos[e.type].begin()){
            if(it!=pos[e.type].end()){
                int nxpos=*it; --it;
                int pvpos=*it; ++it;
                int mid=(nxpos+pvpos)>>1;
                func ref_func(1,-pvpos,e.type);
                add_func(root,1,MAX,pvpos,mid,ref_func);
            }
            else{
                --it;
                int pvpos=*it; ++it;
                func ref_func(1,-pvpos,e.type);
                add_func(root,1,MAX,pvpos,MAX,ref_func);
            }
        }
        if(it!=pos[e.type].end()){
            if(it!=pos[e.type].begin()){
                int nxpos=*it; --it;
                int pvpos=*it; ++it;
                int mid=(nxpos+pvpos)>>1;
                func ref_func(-1,nxpos,e.type);
                add_func(root,1,MAX,mid+1,nxpos,ref_func);
            }
            else{
                int nxpos=*it;
                func ref_func(-1,nxpos,e.type);
                add_func(root,1,MAX,1,nxpos,ref_func);
            }
        }
        if(pos[e.type].empty())--cnt_type;
    }
}
int getans(int pos){
    return query(root,1,MAX,pos);
}

int main(){
//    freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,qc; cin>>n>>k>>qc;
    E e;
    for(int i=0;i<n;++i){
        int x,t,a,b; cin>>x>>t>>a>>b;
        e.time=a; e.pos=x; e.type=t; e.oc=1; e.match_endtime=b+1;
        es.push_back(e);
        e.time=b+1; e.pos=x; e.type=t; e.oc=-1;
        es.push_back(e);
    }
    Q q;
    for(int i=0;i<qc;++i){
        int l,y; cin>>l>>y;
        q.pos=l; q.time=y; q.id=i;
        qs.push_back(q);
    }
    sort(es.begin(),es.end(),[&](const E &a,const E &b){return a.time<b.time;});
    sort(qs.begin(),qs.end(),[&](const Q &a,const Q &b){return a.time<b.time;});
    vector<E>::iterator it=es.begin();
    for(Q &q:qs){
        while(it!=es.end() && it->time<=q.time)do_event(*it),++it;
        if(cnt_type<k)ans[q.id]=-1;
        else ans[q.id]=getans(q.pos);
    }
    for(int i=0;i<qc;++i)cout<<ans[i]<<'\n';
}



