#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct event{
    int type,l,r,v;
};

bool inv;
#define lb(x) ((x)&-(x))
ll bit[100005];
void add(int x,int v){
    if(inv)x=100003-x;
    for(;x<100005;x+=lb(x))bit[x]+=v;
}
ll query(int x,ll v=0){
    if(inv)x=100003-x;
    for(;x;x-=lb(x))v+=bit[x];
    return v;
}
ll presum(int i,int j){
    return query(j)-query(i-1);
}

ll ans[100005];
vector<event> ev;
int a[100005];
set<int> number_append[100005];
pair<int,int> record_laser[100005];

void print(vector<event> ve){
    cout<<"[";
    for(auto i:ve){
        cout<<" ("<<i.type<<":["<<i.l<<","<<i.r<<"]="<<i.v<<")";
    } cout<<" ]";
}

void cdq(vector<event> &ev){
    int n=ev.size();
    if(n<=1)return;
    vector<event> pro,le,re;
    int mid=n/2;
    for(int i=0;i<mid;++i){
        if(ev[i].type==1)pro.push_back(ev[i]);
        le.push_back(ev[i]);
    }
    for(int i=mid;i<n;++i){
        if(ev[i].type==2)pro.push_back(ev[i]);
        re.push_back(ev[i]);
    }
    sort(pro.begin(),pro.end(),[](const event &a,const event &b){return a.r==b.r?a.l==b.l?a.type<b.type:a.l>b.l:a.r<b.r;});
    for(auto &i:pro){
        if(i.type==1){
            add(i.l,i.v);
        }
        else{
            ans[i.v]+=query(i.l);
        }
    }
    for(auto &i:pro)if(i.type==1)add(i.l,-i.v);
    cdq(le); cdq(re);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        add(i,a[i]);
        number_append[a[i]].insert(i);
        if(number_append[a[i]].size()>1u){
            auto it=number_append[a[i]].end();
            --it; --it;
            ev.push_back({1,*it,i,-a[i]});
        }
    }
    int q=0;
    for(int i=0;i<m;++i){
        int type; cin>>type;
        if(type==1){
            int p,v; cin>>p>>v;
            int ori=a[p]; a[p]=v;
            auto oit=number_append[ori].lower_bound(p);
            int L=-1,R=-1;
            ++oit; if(oit!=number_append[ori].end()){
                R=*oit;
            } --oit;
            if(oit!=number_append[ori].begin()){
                --oit; L=*oit; ++oit;
            }
            if(R!=-1)ev.push_back({1,p,R,ori});
            if(L!=-1)ev.push_back({1,L,p,ori});
            if(L!=-1 && R!=-1)ev.push_back({1,L,R,-ori});
            number_append[ori].erase(oit);

            auto nit=number_append[v].lower_bound(p);
            L=-1,R=-1;
            if(nit!=number_append[v].end())R=*nit;
            if(nit!=number_append[v].begin()){
                --nit; L=*nit; ++nit;
            }
            if(L!=-1 && R!=-1)ev.push_back({1,L,R,v});
            if(L!=-1)ev.push_back({1,L,p,-v});
            if(R!=-1)ev.push_back({1,p,R,-v});
            number_append[v].insert(p);

            add(p,v-ori);
        }
        else if(type==2){
            int l,r,v; cin>>l>>r>>v;
            record_laser[l]={r,v};
            ev.push_back({1,l,r,v});
        }
        else if(type==3){
            int l; cin>>l;
            ev.push_back({1,l,record_laser[l].first,-record_laser[l].second});
        }
        else{
            int l,r; cin>>l>>r;
            ans[q]=presum(l,r);
            ev.push_back({2,l,r,q}); ++q;
        }
    }
    memset(bit,0,sizeof(bit));
    inv=1;
    cdq(ev);
    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
}

