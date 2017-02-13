#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int n,k;
struct cup{int l,r;} cps[300005];
struct evt{int tp,x,i;} es[600006];
struct ri{int r,i;};
bool operator<(const ri &a,const ri &b){return a.r!=b.r?a.r<b.r:a.i<b.i;}
bool cmpx(const evt &a,const evt &b){return a.x!=b.x?a.x<b.x:a.tp<b.tp;}
vector<int> ans; set<ri> rs;
int mx;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d%d",&cps[i].l,&cps[i].r);
        es[i*2].x=cps[i].l, es[i*2+1].x=++cps[i].r;
        es[i*2].i=es[i*2+1].i=i;
        es[i*2].tp=1,es[i*2+1].tp=1;
    }
    sort(es,es+2*n,cmpx);
    for(int i=0;i<(2*n);++i){
        if(es[i].tp==1){
            rs.insert({cps[es[i].i].r,es[i].i});
            if((int)rs.size()>=k){
                mx=max(mx,rs.begin()->r-es[i].x);
                rs.erase(rs.begin());
            }
        }
        else{
            auto it=rs.find({es[i].x,es[i].i});
            if(it!=rs.end())rs.erase(it);
        }
    }
    rs.clear();
    for(int i=0;i<(2*n);++i){
        if(es[i].tp==1){
            rs.insert({cps[es[i].i].r,es[i].i});
            if((int)rs.size()>=k){
                if(rs.begin()->r-es[i].x==mx){
                    ans.clear();
                    for(auto it:rs)ans.push_back(it.i);
                    break;
                }
                rs.erase(rs.begin());
            }
        }
        else{
            auto it=rs.find({es[i].x,es[i].i});
            if(it!=rs.end())rs.erase(it);
        }
    }
    printf("%d\n",mx);
    if(ans.empty())for(int i=1;i<=k;++i)printf("%d ",i);
    for(int i:ans)printf("%d ",i+1);puts("");
}
