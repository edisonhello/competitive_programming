#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define mid ((l+r)>>1)

int n,m;
int d[100005],a[100005];
struct st{int id,d;} lstd[100005];
bool cmp_d(const st &a,const st &b){return a.d<b.d;}

bool tryDay(int nn){
    // cout<<"try "<<nn<<endl;
    memset(lstd+1,-1,sizeof(int)*m*2);
    // for(int i=1;i<=n;++i)cout<<lstd[i].<<" ";cout<<endl;
    for(int i=1;i<=nn;++i)lstd[d[i]].d=i,lstd[d[i]].id=d[i];
    for(int i=1;i<=m;++i)if(!~(lstd[i].d))return 0;
    // cout<<"all have"<<endl;
    sort(lstd+1,lstd+m+1,cmp_d);
    // for(int i=1;i<=m;++i)cout<<"work "<<lstd[i].id<<" day "<<lstd[i].d<<endl;
    int now=0;
    for(int i=1;i<=m;++i){
        // cout<<"do "<<lstd[i].id<<endl;
        now+=a[lstd[i].id]+1;
        // cout<<": now="<<now<<" "<<lstd[i].d<<endl;
        if(now>lstd[i].d)return 0;
    }
    return 1;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>d[i];
    for(int i=1;i<=m;++i)cin>>a[i];
    int l=1,r=n;
    while(r>l){
        if(tryDay(mid))r=mid;
        else l=mid+1;
    }
    if(l==n && !tryDay(n))cout<<-1<<endl;
    else cout<<l<<endl;
}
