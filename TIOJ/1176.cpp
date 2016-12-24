#include<iostream>
#include<algorithm>

using namespace std;

struct _{int i,v;} a[1000006];
bool cmp_v(const _ &a,const _ &b){return a.v==b.v?a.i>b.i:a.v>b.v;}
int n,ans[1000006],BIT[1000006];

inline int LB(int x){return x&-x;}
inline void insert(int x,int k){
    while(x<=n+1){
        BIT[x]=k;
        x+=LB(x);
        cout<<x<<endl;
    }
}
inline int Q(int x){
    int rt=-1;
    while(x<=n+1){
        rt=max(rt,BIT[x]);
        x+=LB(x);
        cout<<"a"<<x<<endl;
    }
    return rt;
}

int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].v;
        a[i].i=i;
    }
    sort(a,a+n,cmp_v);
    // s.insert(n);
    insert(n+1,n);
    for(int i=0;i<n;++i){
        // auto it=s.upper_bound(a[i].i);
        int q=Q(a[i].i+1);
        // if(it==s.end())ans[a[i].i]=n-1-a[i].i;
        if(q==n)ans[a[i].i]=n-1-a[i].i;
        // else ans[a[i].i]=*it-a[i].i;
        else ans[a[i].i]=q-a[i].i;
        insert(a[i].i+1,a[i].i);
    }
    ans[n-1]=0;
    for(int i=0;i<n;++i){
        cout<<ans[i]<<endl;
    }
}
