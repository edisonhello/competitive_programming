#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double

ld slope[111];

struct pt{
    ld x,y;
    pt(ld x=0,ld y=0):x(x),y(y){}
};
bool operator<(const pt &a,const pt &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
struct line{
    int id;
    ld a,b,c;
    vector<pair<pt,int>> inter;
    line(pt pa=pt(),pt pb=pt()){
        a=pb.x-pa.x;
        b=pb.y-pa.y;
        swap(a,b); a=-a;
        c=-(pa.x*a+pa.y*b);
        if(a<0)a=-a,b=-b,c=-c; // a>=0
    }
    ld getSlope(){
        if(abs(b)<1e-10)return 1e18;
        else return -a/b;
    }
    bool online(pt p){
        return abs(p.x*a+p.y*b+c)<1e-10;
    }
    pair<pt,int> getNext(pt now,int &dir){
        if(dir==1){
            auto it=upper_bound(inter.begin(),inter.end(),pair<pt,int>(now,7122));
            if(it==inter.end())return pair<pt,int>(pt(1e18,1e18),id);
            auto nw=*it;
            if(slope[nw.second]>getSlope())dir=-1;
            return nw;
        }
        else{   
            auto it=lower_bound(inter.begin(),inter.end(),pair<pt,int>(now,-7122));
            if(it==inter.begin())return pair<pt,int>(pt(1e18,1e18),id);
            auto nw=*(--it);
            if(slope[nw.second]>0 || slope[nw.second]==1e18)dir=1;
            return nw;
        }
    }
};
pt intersect(line l1,line l2){
    ld delta=l1.a*l2.b-l1.b*l2.a;
    ld deltax=-l1.c*l2.b+l1.b*l2.c;
    ld deltay=-l1.a*l2.c+l1.c*l2.a;
    if(delta==0)return pt(1e18,1e18);
    return pt(deltax/delta,deltay/delta);
}

string name[111];
line l[111];
int perm[111];

int main(){
    int r; ll n; ld x,y; cin>>r>>n>>x>>y;
    for(int i=0;i<r;++i){
        cin>>name[i];
        pt a,b;
        cin>>a.x>>a.y>>b.x>>b.y;
        l[i]=line(a,b);
        l[i].id=i;
        // cout<<"line "<<i<<" argument: "<<l[i].a<<" "<<l[i].b<<" "<<l[i].c<<endl;
        slope[i]=l[i].getSlope();
        // cout<<"slope is "<<slope[i]<<endl;
    }
    for(int i=0;i<r;++i){
        for(int j=i+1;j<r;++j){
            pt its=intersect(l[i],l[j]);
            if(its.x==1e18 && its.y==1e18)continue;
            // cout<<i<<" , "<<j<<" cross at "<<its.x<<" "<<its.y<<endl;
            l[i].inter.emplace_back(its,j);
            l[j].inter.emplace_back(its,i);
        }
    }
    for(int i=0;i<r;++i)sort(l[i].inter.begin(),l[i].inter.end());
    pt now(x,y);
    int atl=-1,dir=1,step=0;
    memset(perm,-1,sizeof(perm));
    for(int i=0;i<r;++i)if(l[i].online(now))atl=i;
    if(atl==-1)exit(7122);
    while(0==0){
        // cout<<"now: "<<now.x<<" "<<now.y<<" , atl: "<<atl<<" , dir: "<<dir<<endl;
        if(perm[atl]!=-1)break;
        perm[atl]=step; ++step;
        tie(now,atl)=l[atl].getNext(now,dir);
        if(now.x==1e18 && now.y==1e18){
            cout<<name[atl]<<endl;
            exit(0);
        }
    }
    for(int i=0;i<r;++i)if(perm[i]==n%step)return cout<<name[i]<<endl,0;
}
