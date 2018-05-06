#include<bits/stdc++.h>
using namespace std;
#define int long long

struct pt{
    int x,y;
    pt(int x=0,int y=0):x(x),y(y){}
};
pt operator+(const pt &a,const pt &b){
    return pt(a.x+b.x,a.y+b.y);
}
pt operator-(const pt &a,const pt &b){
    return pt(a.x-b.x,a.y-b.y);
}
int operator*(const pt &a,const pt &b){
    return a.x*b.x+a.y*b.y;
}
int operator^(const pt &a,const pt &b){
    return a.x*b.y-a.y*b.x;
}
bool operator==(const pt &a,const pt &b){
    return a.x==b.x && a.y==b.y;
}
int sq(const int x){ return x*x; }
int sqd(const pt &a,const pt &b){
    return sq(a.x-b.x)+sq(a.y-b.y);
}

double abs(const pt &p){
    return sqrt(sq(p.x)+sq(p.y));
}

const double eps=1e-8;
const double PI=acos(-1);

pt po[1003];

bool inside(pt l,pt r,pt p){
    if(l==p || r==p)return 1;
    if((p-l)^(p-r))return 0;
    if((p-l)*(p-r)<0)return 1;
    return 0;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=0;i<n;++i)cin>>po[i].x>>po[i].y;
    po[n]=po[0];
    /* sort(po,po+n,[](const po &a,const po &b){
        return a.x<b.x;
    }); */ 
    while(q--){
        pt p; cin>>p.x>>p.y;
        bool ins=0;
        for(int i=0;i<n;++i){
            if(inside(po[i],po[i+1],p))ins=1;
        }
        if(ins){ cout<<"D\n"; continue; }
        double rnd=0;
        for(int i=0;i<n;++i){
            pt vp1=po[i+1]-p;
            pt vp0=po[i]-p;
            double l1=abs(vp1),l0=abs(vp0);
            double cos0=(vp1*vp0)/l1/l0;
            cos0=min((double)1,max((double)-1,cos0));
            // cout<<"cos0: "<<cos0<<endl;
            // cout<<"angl: "<<acos(cos0)<<endl;
            double theta=acos(cos0);

            double sin0=(vp1^vp0);
            if(sin0<0)theta*=-1;

            rnd+=theta;
        }
        /* for(int i=0;i<n;++i){
            pt vp1=po[i+1]-p;
            pt vp0=po[i]-p;
            double l1=abs(vp1),l0=abs(vp0);
            double sin0=(vp1^vp0)/l1/l0;
            sin0=min((double)1,max((double)-1,sin0));
            cout<<"sin0: "<<sin0<<endl;
            cout<<"angl: "<<asin(sin0)<<endl;
            double theta=asin(sin0);

            rnd+=asin(sin0);
        } */


        /* for(int i=0;i<n;++i){
            pt vp1=po[i+1]-p;
            pt vp0=po[i]-p;
            double l1=abs(vp1),l0=abs(vp0);
            double sin0=(vp1^vp0)/l1/l0;
            sin0=min((double)1,max((double)-1,sin0));
            cout<<"sin0: "<<sin0<<endl;
            cout<<"angl: "<<asin(sin0)<<endl;
            double theta=asin(sin0);

            double cos0=(vp1*vp0)/l1/l0;
            cos0=min((double)1,max((double)-1,cos0));
            cout<<"cos0: "<<cos0<<endl;
            if(cos0<0)theta=PI-theta;

            cout<<"theta: "<<theta<<endl;

            rnd+=theta;
        } */
        rnd=abs(rnd);
        // cout<<"rnd: "<<rnd<<endl;
        if(rnd>PI)cout<<"D\n";
        else cout<<"F\n";
    }
    
}
