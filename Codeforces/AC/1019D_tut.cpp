#include<bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll,ll> ps[2002];
int id[2002],pos[2002];
pair<int,int> line[4000006];

int main(){
    int n; cin>>n;
    long long s; cin>>s; s<<=1;
    for(int i=1;i<=n;++i)cin>>ps[i].first>>ps[i].second;
    int m=0;
    for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)line[++m]=make_pair(i,j);
    sort(line+1,line+1+m,[&](const pair<int,int> &a,const pair<int,int> &b)->bool{
        if(ps[a.first].first==ps[a.second].first)return 0;
        if(ps[b.first].first==ps[b.second].first)return 1;
        // return (ps[a.first].second-ps[a.second].second)*(ps[b.first].first-ps[b.second].first)<(ps[b.first].second-ps[b.second].second)*(ps[a.first].first-ps[a.second].first);
        return (double)
(ps[a.first].second-ps[a.second].second)/(ps[a.first].first-ps[a.second].first)
        < (double)
(ps[b.first].second-ps[b.second].second)/(ps[b.first].first-ps[b.second].first);
        // return make_pair(getslope(ps[a.first],ps[a.second]),a.first)<make_pair(getslope(ps[b.first],ps[b.second]),b.first);
    });
    for(int i=1;i<=n;++i)id[i]=i;
    // for(int i=1;i<=n;++i)cout<<ps[i].first<<" "<<ps[i].second<<endl;
    sort(id+1,id+1+n,[&](const int &a,const int &b){ return ps[a]<ps[b]; });
    for(int i=1;i<=n;++i)pos[id[i]]=i;
    // for(int i=1;i<=n;++i)cout<<pos[i]<<" ";
    for(int i=1;i<=m;++i){
        auto l=line[i];
        auto getarea=[&](const pair<ll,ll> &a,const pair<ll,ll> &b,const pair<ll,ll> &c)->ll{ return abs(a.first*b.second+b.first*c.second+c.first*a.second-a.second*b.first-b.second*c.first-c.second*a.first); };

        // cout<<"judging line based on "<<l.first<<" and "<<l.second<<" , pos is "<<pos[l.first]<<" "<<pos[l.second]<<endl;

        int L=1,R=min(pos[l.first],pos[l.second])-1;
        while(R>=L){
            int M=(L+R)>>1;
            ll area=getarea(ps[id[M]],ps[l.first],ps[l.second]);
            // cout<<"this area: "<<area<<endl;
            if(area==s){
                cout<<"Yes"<<endl;
                cout<<ps[id[M]].first<<" "<<ps[id[M]].second<<endl;
                cout<<ps[l.first].first<<" "<<ps[l.first].second<<endl;
                cout<<ps[l.second].first<<" "<<ps[l.second].second<<endl;
                exit(0);
            }
            if(area<s)R=M-1;
            else L=M+1;
        }
        L=max(pos[l.first],pos[l.second])+1,R=n;
        while(R>=L){
            int M=(L+R)>>1;
            ll area=getarea(ps[id[M]],ps[l.first],ps[l.second]);
            // cout<<"this area: "<<area<<endl;
            if(area==s){
                cout<<"Yes"<<endl;
                cout<<ps[id[M]].first<<" "<<ps[id[M]].second<<endl;
                cout<<ps[l.first].first<<" "<<ps[l.first].second<<endl;
                cout<<ps[l.second].first<<" "<<ps[l.second].second<<endl;
                exit(0);
            }
            if(area<s)L=M+1;
            else R=M-1;
        }

        tie(pos[l.first],pos[l.second],id[pos[l.first]],id[pos[l.second]])=make_tuple(pos[l.second],pos[l.first],l.second,l.first);
    }
    cout<<"No"<<endl;
}
