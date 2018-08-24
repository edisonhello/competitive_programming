#include<bits/stdc++.h>
using namespace std;
#define ld long double

struct point{ld x,y;
point(ld x=0,ld y=0):x(x),y(y){}};

const ld eps=1e-10;

ld w,v,u;
vector<point> pt,uch,lch;

ld gtwpp(ld y){return y/u;}
ld gtwbc(ld x){return x/v;}
bool ttsbic(){
    for(auto &i:pt)if(gtwpp(i.y)>gtwbc(i.x))return 0;
    return cout<<fixed<<setprecision(15)<<gtwpp(w)<<endl,1;
}
bool saic(){
    ld mxtm=-1;
    for(auto &i:lch)mxtm=max(mxtm,gtwbc(i.x)+(w-i.y)/u);
    return cout<<fixed<<setprecision(15)<<max(mxtm,gtwpp(w))<<endl,1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    cin>>w>>v>>u;
    for(int i=0;i<n;++i){
        ld x,y; cin>>x>>y;
        pt.emplace_back(x,y);
    }
    vector<point>::iterator lstp,rstp;
    ld lstpx=1e10,lstpy=-1,rstpx=-1,rstpy=-1;
    for(int id=0;id<n;++id){
        auto &i=pt[id];
        if(i.x<lstpx or (abs(i.x-lstpx)<eps and i.y<lstpy))lstpx=i.x, lstpy=i.y, lstp=pt.begin()+id;
        if(i.x>rstpx)rstpx=i.x, rstpy=i.y, rstp=pt.begin()+id;
    }
    for(auto it=lstp;it!=rstp;++it){
        if(it==pt.end())it=pt.begin();
        if(it==rstp)break;
        lch.push_back(*it);
    } lch.push_back(*rstp);
    for(auto it=rstp;it!=lstp;++it){
        if(it==pt.end())it=pt.begin();
        if(it==lstp)break;
        uch.push_back(*it);
    }
    ttsbic() || saic();
}
