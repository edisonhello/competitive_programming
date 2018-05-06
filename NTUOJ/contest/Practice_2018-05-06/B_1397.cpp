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
int operator^(const pt &a,const pt &b){
    return a.x*b.y-a.y*b.x;
}
int sq(const int x){ return x*x; }
int sqd(const pt &a,const pt &b){
    return sq(a.x-b.x)+sq(a.y-b.y);
}

const double eps=1e-8;

int aras[50005],pre[50005];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    bool first=1;
    int n,q; while(cin>>n>>q,n){
        if(!first)cout<<'\n';
        else first=0;
        memset(aras,0,sizeof(aras));
        memset(pre,0,sizeof(pre));
        vector<pt> po(n);
        for(int i=0;i<n;++i)cin>>po[i].x>>po[i].y;
        for(int i=0;i<n-1;++i){
            aras[i]=po[i]^po[i+1];
        }
        aras[n-1]=po[n-1]^po[0];
        pre[0]=aras[0];
        for(int i=1;i<n;++i)pre[i]=pre[i-1]+aras[i];
        int tot=abs(pre[n-1]);
        // for(int i=0;i<n;++i)cout<<"ara["<<i<<"]="<<aras[i]<<endl;
        // cout<<"de, tot: "<<tot<<endl;
        while(q--){
            int a,b; cin>>a>>b;
            int seg=pre[b-1]-(a?pre[a-1]:0);
            int qaa=abs(seg+(po[b]^po[a]));
            int qab=tot-qaa;
            int qa=min(qaa,qab);
            // cout<<"de, seg: "<<seg<<endl;
            // cout<<"de: "<<(po[b]^po[a])<<endl;
            // cout<<"de "<<qaa<<" "<<qab<<endl;
            // cout<<qa<<'\n';
            cout<<(qa>>1)<<".";
            cout<<(qa&1?'5':'0')<<'\n';
        }
    }
}
