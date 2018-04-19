#include<bits/stdc++.h>
using namespace std;

int a[1004],b[1004],l[1004],r[1004],ad1[1004],ad2[1004],bd1[1004],bd2[1004];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;++i)cin>>b[i];
    sort(b,b+n,greater<int>());
    auto cd=[&](int *a,int *d1,int *d2){for(int i=0;i<n;++i){
        int x=a[i];
        while(x>1)++d1[i],x>>=1;
        x=a[i]-(1<<d1[i])+1;
        d2[i]=d1[i]-(x<=(1<<(d1[i]-1)));
    }};
    cd(a,ad1,ad2); cd(b,bd1,bd2);
    int L=1e9,R=-1e9;
    // for(int i=0;i<n;++i)cout<<i<<" "<<ad1[i]<<" "<<ad2[i]<<endl;
    // for(int i=0;i<n;++i)cout<<i<<" "<<bd1[i]<<" "<<bd2[i]<<endl;
    for(int i=0;i<n;++i){
        l[i]=max({ad1[i]+ad2[i],bd1[i]+bd2[i],ad1[i]+bd1[i]+1});
        r[i]=ad1[i]+ad2[i]+bd1[i]+bd2[i]+1;
        L=min(L,l[i]), R=max(R,r[i]);
        // cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
    }
    long long ans=1ll<<60;
#define sq(x) (1ll*(x)*(x))
    for(int d=L;d<=R;++d){
        int tot=0;
        for(int i=0;i<n;++i){
            if(d<l[i])tot+=l[i];
            else if(d>r[i])tot+=r[i];
            else tot+=d;
        }
        // cout<<"d: "<<d<<" , tot: "<<tot<<endl;
        long long ta=0;
        for(int i=0;i<n;++i){
            if(d<l[i])ta+=sq(l[i]*n-tot);
            else if(d>r[i])ta+=sq(r[i]*n-tot);
            else ta+=sq(d*n-tot);
        }
        ans=min(ans,ta);
    }
    cout<<ans<<endl;
}
