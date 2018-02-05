#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>
#define ll long long

pii pt[100005];
ll top,bot,rig,lef;
ll _top,_rig,_bot,_lef;
ll __top,__rig,__bot,__lef;
int n;
bitset<100005> cv,cvb;

void init(ll &a,ll &b,ll &c,ll &d){
    a=b=-1000000009; c=d=1000000009;
}

bool can3(ll r){
    return __rig-__lef<=r && __top-__bot<=r;
}

bool can2(ll r){
    cvb=cv;

    init(__top,__rig,__bot,__lef);
    for(int i=0;i<n;++i){
        if(cv[i])continue;
        if(pt[i].first>=_rig-r && pt[i].second>=_top-r)cv[i]=1;
        else __rig=max(__rig,pt[i].first),__lef=min(__lef,pt[i].first),__top=max(__top,pt[i].second),__bot=min(__bot,pt[i].second);
    }
    // cout<<"second at top right: cv: "<<cv.count()<<endl;
    // cout<<"four side: "<<__top<<" "<<__bot<<" "<<__rig<<" "<<__lef<<endl;
    if(cv.count()==n || can3(r))return 1;
    
    cv=cvb;
    init(__top,__rig,__bot,__lef);
    for(int i=0;i<n;++i){
        if(cv[i])continue;
        if(pt[i].first<=_lef+r && pt[i].second>=_top-r)cv[i]=1;
        else __rig=max(__rig,pt[i].first),__lef=min(__lef,pt[i].first),__top=max(__top,pt[i].second),__bot=min(__bot,pt[i].second);
    }
    // cout<<"second at top left: cv: "<<cv.count()<<endl;
    // cout<<"four side: "<<__top<<" "<<__bot<<" "<<__rig<<" "<<__lef<<endl;
    if(cv.count()==n || can3(r))return 1;
    // cout<<"no can"<<endl;
    return 0;
}

bool can(ll r){
    // cout<<"in r: "<<r<<endl;
    cv.reset(); 
    init(_top,_rig,_bot,_lef);
    for(int i=0;i<n;++i){
        if(pt[i].first>=rig-r && pt[i].second>=top-r)cv[i]=1;
        else _rig=max(_rig,pt[i].first),_lef=min(_lef,pt[i].first),_top=max(_top,pt[i].second),_bot=min(_bot,pt[i].second);
    }
    // cout<<"first at top right: cv: "<<cv.count()<<endl;
    // cout<<"four side: "<<_top<<" "<<_bot<<" "<<_rig<<" "<<_lef<<endl;
    if(cv.count()==n || can2(r))return 1;

    cv.reset(); 
    init(_top,_rig,_bot,_lef);
    for(int i=0;i<n;++i){
        if(pt[i].first<=lef+r && pt[i].second>=top-r)cv[i]=1;
        else _rig=max(_rig,pt[i].first),_lef=min(_lef,pt[i].first),_top=max(_top,pt[i].second),_bot=min(_bot,pt[i].second);
    }
    // cout<<"first at top left: cv: "<<cv.count()<<endl;
    // cout<<"four side: "<<_top<<" "<<_bot<<" "<<_rig<<" "<<_lef<<endl;
    if(cv.count()==n || can2(r))return 1;

    cv.reset(); 
    init(_top,_rig,_bot,_lef);
    for(int i=0;i<n;++i){
        if(pt[i].first>=rig-r && pt[i].second<=bot+r)cv[i]=1;
        else _rig=max(_rig,pt[i].first),_lef=min(_lef,pt[i].first),_top=max(_top,pt[i].second),_bot=min(_bot,pt[i].second);
    }
    // cout<<"first at bot right: cv: "<<cv.count()<<endl;
    // cout<<"four side: "<<_top<<" "<<_bot<<" "<<_rig<<" "<<_lef<<endl;
    if(cv.count()==n || can2(r))return 1;

    cv.reset(); 
    init(_top,_rig,_bot,_lef);
    for(int i=0;i<n;++i){
        if(pt[i].first<=lef+r && pt[i].second<=bot+r)cv[i]=1;
        else _rig=max(_rig,pt[i].first),_lef=min(_lef,pt[i].first),_top=max(_top,pt[i].second),_bot=min(_bot,pt[i].second);
    }
    // cout<<"first at bot left: cv: "<<cv.count()<<endl;
    // cout<<"four side: "<<_top<<" "<<_bot<<" "<<_rig<<" "<<_lef<<endl;
    if(cv.count()==n || can2(r))return 1;
    // cout<<"no can!"<<endl;
    return 0;
}

int main(){
    int ts; cin>>ts; while(ts--){
        cin>>n;
        for(int i=0;i<n;++i)cin>>pt[i].first>>pt[i].second;
        top=rig=-1000000009;
        bot=lef= 1000000009;
        for(int i=0;i<n;++i)rig=max(rig,pt[i].first),lef=min(lef,pt[i].first),top=max(top,pt[i].second),bot=min(bot,pt[i].second);
        long long l=0,r=2000000009;
        while(r>l){
            long long mid=(l+r)>>1;
            if(can(mid))r=mid;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
}
