#include<bits/stdc++.h>
using namespace std;

struct pp{
    int x,y,z,i;
};
bool ss[500008];
vector<pp> p;
vector<int> numy,numz;
int bit[500008];

#define lb(x) ((x)&-(x))
void add(int x,int v){
    for(;x<500008;x+=lb(x))bit[x]+=v;
}
int qry(int x,int v=0){
    for(;x;x-=lb(x))v+=bit[x]; return v;
}

void cdq(int l,int r,vector<pp> &p){
    if(l==r or p.empty() or p[0].x==p.back().x)return;
    // cout<<"cdq: "<<l<<" "<<r<<" with p size: "<<p.size()<<endl;
    // cout<<"p: "; for(auto &i:p)cout<<i.i<<", "; cout<<endl;
    int m=(l+r)>>1;
    // for(auto &i:p){
    //     if(i.y>m)cout<<"for i: "<<i.i<<", i.y: "<<i.y<<" <=m: "<<m<<endl;
    // }
    for(auto &i:p){
        if(i.y>m)add(500005-i.z,1);
        else ss[i.i]|=!!qry(500005-i.z-1);// , cout<<"ss "<<i.i<<": "<<ss[i.i]<<endl;
    }
    vector<pp> pl,pr;
    for(auto &i:p){
        if(i.y>m)add(500005-i.z,-1),pr.push_back(i);
        else pl.push_back(i);
    }
    cdq(l,m,pl); cdq(m+1,r,pr);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; p.resize(n);
    for(int i=0;i<n;++i)cin>>p[i].x,p[i].i=i;
    for(int i=0;i<n;++i)cin>>p[i].y,numy.push_back(p[i].y); sort(numy.begin(),numy.end());
    for(int i=0;i<n;++i)cin>>p[i].z,numz.push_back(p[i].z); sort(numz.begin(),numz.end());
    for(int i=0;i<n;++i)p[i].y=lower_bound(numy.begin(),numy.end(),p[i].y)-numy.begin();
    for(int i=0;i<n;++i)p[i].z=lower_bound(numz.begin(),numz.end(),p[i].z)-numz.begin()+1;
    sort(p.begin(),p.end(),[](const pp &a,const pp &b){return a.x==b.x?a.y==b.y?a.z<b.z:a.y<b.y:a.x>b.x;});
    cdq(0,n-1,p); int ans=0;
    for(int i=0;i<n;++i)if(ss[i])++ans; cout<<ans<<endl;
    // for(int i=0;i<n;++i)if(ss[i])cout<<"i: "<<i<<", ss"<<endl;
}
