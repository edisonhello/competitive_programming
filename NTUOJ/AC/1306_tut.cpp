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

bool inside(pt l,pt r,pt p){
    if(l==p || r==p)return 1;
    if((p-l)^(p-r))return 0;
    if((p-l)*(p-r)<0)return 1;
    return 0;
}

struct seg{
    pt a,b;
    seg(pt a=pt(),pt b=pt()):a(a),b(b){}
};

bool dfs(seg s,pt pa,pt pb){
    return ((pa-s.a)^(s.b-s.a))*((pb-s.a)^(s.b-s.a))<=0;
}
bool banana(seg &a,seg &b){
    if(((a.a-a.b)^(b.a-b.b))==0){
        if(inside(a.a,a.b,b.a))return 1;
        if(inside(a.a,a.b,b.b))return 1;
        if(inside(b.a,b.b,a.a))return 1;
        if(inside(b.a,b.b,a.b))return 1;
        return 0;
    }
    return dfs(a,b.a,b.b) && dfs(b,a.a,a.b);
}

pt po[100005];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; while(cin>>n){
        for(int i=0;i<n;++i)cin>>po[i].x>>po[i].y;
        po[n]=po[0];
        int tot=0;
        for(int i=0;i<n;++i)tot+=po[i+1]^po[i];
        tot=abs(tot);
        tot<<=1;
        for(int i=0;i<n;++i){
            if(po[i].x==po[i+1].x){
                tot-=abs(po[i].y-po[i+1].y);
            }
            else if(po[i].y==po[i+1].y){
                tot-=abs(po[i].x-po[i+1].x);
            }
        }
        cout<<(tot>>1)<<"."<<(tot&1?"5":"0")<<'\n';
    }
    
}
