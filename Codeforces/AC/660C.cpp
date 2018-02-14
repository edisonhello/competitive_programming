#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pii pair<int,int> 
#define pipii pair<int,pair<int,int>> 

int a[300005];
int k;

#define mid ((l+r)>>1)
pair<int,pair<int,int>> DC(int l,int r){
    if(l==r)return k?mp(1,mp(l,l)):mp(a[l],a[l]?mp(l,l):mp(-1,-1));
    pipii la=DC(l,mid),ra=DC(mid+1,r);
    int kleft=k;
    int ll=mid+1,rr=mid;
    while(ll>l && (a[ll-1]==1 || (a[ll-1]==0 && kleft>0))){
        --ll;
        if(a[ll]==0)--kleft;
    }
    while(rr<r && (a[rr+1]==1 || (a[rr+1]==0 && kleft>0))){
        ++rr;
        if(a[rr]==0)--kleft;
    }
    pipii ans=max(la,ra);
    if(rr-ll+1>ans.first)ans=mp(rr-ll+1,mp(ll,rr));
     
    while(ll<=mid){
        if(a[ll]==0)++kleft;
        ++ll;
        while(rr<r && (a[rr+1]==1 || (a[rr+1]==0 && kleft>0))){
            ++rr;
            if(a[rr]==0)--kleft;
        }
        if(rr-ll+1>ans.first)ans=mp(rr-ll+1,mp(ll,rr));
    }
    return ans;
}

int main(){
    int n; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    pipii ans=DC(1,n);
    cout<<ans.first<<endl;
    for(int i=1;i<=n;++i){
        if(ans.second.first<=i && i<=ans.second.second)cout<<1<<" ";
        else cout<<a[i]<<" ";
    }
    cout<<endl;
}
