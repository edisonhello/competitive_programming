#include<bits/stdc++.h>
using namespace std;
#define ld double

struct pnt{
    ld x,y,z;
    pnt(ld x=0,ld y=0,ld z=0):x(x),y(y),z(z){}
};
pnt operator+(const pnt &a,const pnt &b){
    return pnt(a.x+b.x,a.y+b.y,a.z+b.z);
}
pnt operator-(const pnt &a,const pnt &b){
    return pnt(a.x-b.x,a.y-b.y,a.z-b.z);
}
pnt operator*(const pnt &a,const ld x){
    return pnt(a.x*x,a.y*x,a.z*x);
}
pnt operator/(const pnt &a,const ld x){
    return pnt(a.x/x,a.y/x,a.z/x);
}
/* ld operator()(const pnt &a){
    return sqrt(pow(a.x,2)+pow(a.y,2)+pow(a.z,2));
} */
ostream& operator<<(ostream &ostm,const pnt &a){
    ostm<<"("<<a.x<<","<<a.y<<","<<a.z<<")";
    return ostm;
}

void solve(ld A){
    pnt O(0,0,0);
    pnt L(sqrt(2),1,0),R(0,sqrt(3),0);
    int cnt=100;
    pnt ans1,ans2,ans3;
    while(cnt--){
        pnt oppo=(L+R)/2;
        pnt rrrr=oppo/3*2;
            swap(rrrr.x,rrrr.y);
            rrrr.y*=-1;
            rrrr=rrrr/sqrt(2);
            rrrr=oppo/3*2+rrrr;
        pnt llll=oppo-rrrr;
        pnt pnt3=rrrr/2;
            pnt3.z+=1.0/sqrt(2);
        pnt pnt2=pnt3+llll;
        pnt pnt5=rrrr/2;
            pnt5.z-=1.0/sqrt(2);
        pnt pnt6=pnt5+llll;
        pnt pnts[]={llll,pnt2,pnt3,rrrr,pnt5,pnt6,llll};
        ld area=0;
        for(int i=0;i<6;++i){
            area+=pnts[i].x*pnts[i+1].z-pnts[i].z*pnts[i+1].x;
        }
        area=abs(area)/2;
        if(area>A)R=oppo;
        else L=oppo;
        cout<<oppo<<" "<<area<<endl;
        ans1=pnt2/2-oppo/2;
        ans2=rrrr/2-oppo/2;
        ans3=pnt6/2-oppo/2;
    }
    cout<<fixed<<setprecision(12)<<ans1.x<<" "<<ans1.y<<" "<<ans1.z<<endl;
    cout<<fixed<<setprecision(12)<<ans2.x<<" "<<ans2.y<<" "<<ans2.z<<endl;
    cout<<fixed<<setprecision(12)<<ans3.x<<" "<<ans3.y<<" "<<ans3.z<<endl;
}

int main(){
    int ts,ks=0; cin>>ts; while(ts--){
        cout<<"Case #"<<(++ks)<<":"<<endl;
        ld A; cin>>A;
        solve(A);
    }
}

