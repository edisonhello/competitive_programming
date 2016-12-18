#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

struct _{int r,x,y,i;} a[100005];
bool cmp_xy(const _ &a,const _ &b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
bool cmp_i(const _ &a,const _ &b){return a.i<b.i;}

const int Z=1e9+7;

int N,Q,pos[100005],invpos[100005],lcpa[100005],lcpl,spt[20][100005];
char c[200005];

char proc(ll base,int b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*base%Z;
        base=base*base%Z;
        b>>=1;
    }
    if(ans==1)return 'a';
    else return 'b';
}


int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>N>>Q;
    for(int i=0,t;i<N;++i){cin>>t;c[i]=a[i].x=proc(t,(Z-1)>>1);a[i].i=i;/*cout<<c[i]<<" ";*/}/*cout<<endl;*/

    sort(a,a+N,cmp_xy);
    a[0].r=1;for(int i=1;i<N;++i)if(a[i].x==a[i-1].x&&a[i].y==a[i-1].y)a[i].r=a[i-1].r;else a[i].r=a[i-1].r+1;
    for(int i=0;i<N;++i)a[i].x=a[i].r;
    for(int D=1;D<N;D<<=1){
        sort(a,a+N,cmp_i);
        for(int i=0;i<N;++i)a[i].y=c[i+D];
        sort(a,a+N,cmp_xy);
        a[0].r=1;for(int i=1;i<N;++i)if(a[i].x==a[i-1].x&&a[i].y==a[i-1].y)a[i].r=a[i-1].r;else a[i].r=a[i-1].r+1;
        for(int i=0;i<N;++i)a[i].x=a[i].r;
    }
    for(int i=0;i<N;++i)pos[a[i].i]=i;
    for(int i=0;i<N;++i,--lcpl){
        if(pos[i]==0)continue;
        if(lcpl<0)lcpl=0;
        while(a[pos[i]].i+lcpl>=N||a[pos[i]-1].i+lcpl>=N)--lcpl;
        while(a[pos[i]].i+lcpl<N&&a[pos[i]-1].i+lcpl<N&&c[a[pos[i]].i+lcpl]==c[a[pos[i]-1].i+lcpl])++lcpl;
        spt[0][i]=lcpl;
        // cout<<i<<" "<<lcpl<<endl;
    }

    for(int i=0;i<N;++i)invpos[pos[i]]=i;
    cout<<"pos: ";for(int i=0;i<N;++i)cout<<pos[i]<<" ";cout<<endl;
    cout<<"lcp: ";for(int i=0;i<N;++i)cout<<spt[0][i]<<" ";cout<<endl;

    for(int D=1,d=1;D<N;D<<=1,++d){
        for(int i=0;i+D<N;++i){
            spt[d][i]=min({spt[d-1][i],spt[d-1][i+D]});
        }
    }
    while(Q--){
        int a,b;
        cin>>a>>b;
        if(a==b){cout<<N-a<<endl;continue;}
        int mn=0x7f7f7f7f;
        if(pos[a]>pos[b])swap(a,b);
        for(int i=pos[a]+1;i<=pos[b];++i){
            mn=min(mn,spt[0][invpos[i]]);
        }
        cout<<mn<<endl;
    }
}
