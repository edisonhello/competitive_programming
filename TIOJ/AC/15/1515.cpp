#include<iostream>
#include<algorithm>
using namespace std;
#define SA sa,sa+n
struct st{
    int x,y,r,n;
} sa[200005];
vector<st> cnt[200005];
bool cmp_xy(const st &a,const st &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
bool cmp_y(const st &a,const st &b){return a.y<b.y;}
bool cmp_n(const st &a,const st &b){return a.n<b.n;}

int n,lcpa[200005],pos[200005];string s;

inline void printS(int st){for(int i=st;i<n;++i)cout<<s[i];}

void radixsort(){
    int hi=0;
    for(int i=0;i<n;++i)cnt[sa[i].y].push_back(sa[i]),hi=max({hi,sa[i].y});
    for(int ptr=0,pos=0;ptr<=hi;++ptr){
        if(cnt[ptr].empty())continue;
        for(auto &i:cnt[ptr])sa[pos++]=i;
        cnt[ptr].clear();
    }
    hi=0;
    for(int i=0;i<n;++i)cnt[sa[i].x].push_back(sa[i]),hi=max({hi,sa[i].x});
    for(int ptr=0,pos=0;ptr<=hi;++ptr){
        if(cnt[ptr].empty())continue;
        for(auto &i:cnt[ptr])sa[pos++]=i;
        cnt[ptr].clear();
    }
}

void doLCP(){
    int lcp=0,lcpx=0;
    for(int i=0;i<n;++i)pos[sa[i].n]=i;
    // cout<<"pos: ";for(int i=0;i<n;++i)cout<<pos[i]<<" ";cout<<endl;
    for(int i=0;i<n;++i,--lcp){
        if(lcp<0)lcp=0;
        if(pos[i]==0)continue;
        lcp=min({lcp,n-sa[pos[i]].n,n-sa[pos[i]-1].n});
        while(lcp+sa[pos[i]].n<n && lcp+sa[pos[i]-1].n<n && s[lcp+sa[pos[i]].n]==s[lcp+sa[pos[i]-1].n])++lcp;
        lcpa[i]=lcp;
        lcpx=max(lcpx,lcp);
    }
    // for(int i=0;i<n;++i)cout<<lcpa[i]<<" ";cout<<endl;
    cout<<lcpx<<endl;
}

void doSA(){
    radixsort();
    // sort(SA,cmp_xy);
    sa[0].r=1;
    for(int i=1;i<n;++i){
        sa[i].r=sa[i-1].r;
        if(cmp_xy(sa[i-1],sa[i]))++sa[i].r;
    }
    for(int D=1;D<n;D<<=1){
        // for(int i=0;i<n;++i){cout<<sa[i].n<<" ";printS(sa[i].n);cout<<endl;}cout<<endl;
        for(int i=0;i<n;++i)pos[sa[i].n]=i;
        for(int i=0;i<n;++i){
            if(sa[i].n+D>=n)sa[i].y=0;
            else sa[i].y=sa[pos[sa[i].n+D]].x;
        }
        radixsort();
        // sort(SA,cmp_xy);
        sa[0].r=1;
        for(int i=1;i<n;++i){
            sa[i].r=sa[i-1].r;
            if(cmp_xy(sa[i-1],sa[i]))++sa[i].r;
        }
        for(int i=0;i<n;++i)sa[i].x=sa[i].r;
        if(sa[n-1].r==n)break;
    }
    // for(int i=0;i<n;++i){cout<<sa[i].n<<" ";printS(sa[i].n);cout<<endl;}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;++i){
        sa[i].n=i;
        sa[i].x=s[i];
    }
    doSA();
    doLCP();
}
