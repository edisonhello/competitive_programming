#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;

int a[200005];
int lislen[200005],lislast[200005];
int ldslen[200005],ldslast[200005];
// rope<int> *lis[200005];

int main(){
    int n,x; cin>>n>>x;
    for(int i=1;i<=n;++i)cin>>a[i];
    vector<int> lis(1,a[1]);
    // lislen[1]=1; lislast[1]=a[1];
    // lis[0]=new rope<int>();
    for(int i=1;i<=n;++i){
        // lis[i]=new rope<int>(lis[i-1]);
        if(lis.empty() || a[i]>lis.back())lis.push_back(a[i]);
        else *lower_bound(lis.begin(),lis.end(),a[i])=a[i];
        lislen[i]=lis.size(); lislast[i]=lis.back();
    }
    int ans=0;
    vector<int> lds;
    for(int i=n;i>=1;--i){
        if(lds.empty() || a[i]<lds.back())lds.push_back(a[i]);
        else *lower_bound(lds.begin(),lds.end(),a[i],greater<int>())=a[i];
        ans=max(ans,lislen[i-1]+int(lds.rend()-upper_bound(lds.rbegin(),lds.rend(),lislast[i-1]-x)));
        ldslen[i]=lds.size(); ldslast[i]=lds.back();
        // cout<<"in i: "<<i<<" get ans "<<ans<<" , lislen[i-1]="<<lislen[i-1]<<endl;
        // cout<<"now lds: "; for(int i:lds)cout<<i<<" "; cout<<endl;
    }
    cout<<ans<<endl;
    /* lis.clear();
    for(int i=1;i<=n;++i){
        if(lis.empty() || a[i]>lis.back())lis.push_back(a[i]);
        else *lower_bound(lis.begin(),lis.end(),a[i])=a[i];
        ans=max(ans,ldslen[i+1]+(i==n?int(lis.size()):int(upper_bound(lis.begin(),lis.end(),ldslast[i+1]+x-1)-lis.begin())));
        // cout<<"in i="<<i<<" , get "<<ans<<endl;
        // cout<<"ldslen: "<<ldslen[i+1]<<" now lis len: "<<lis.size()<<endl;
    }
    cout<<ans<<endl; */
}
// fake solution but get 62 pts
// WA testdata: "10 10\n1 2 4 10 11 5 -4 -3 -2 -1\n"
