#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
pair<int,int> pt[100005];
int premn[100005],premx[100005],sufmn[100005],sufmx[100005];

bool check(int wid){
    // cout<<"checking "<<wid<<endl;
    int L=1,R=0;
    for(;L<=n;++L){
        while(R<n && ((pt[R+1].first-pt[R+1].second)-(pt[L].first-pt[L].second))<=wid*2)++R;
        int mx=-(1ll<<40),mn=1ll<<40;
        if(L>1)mx=max(mx,premx[L-1]),mn=min(mn,premn[L-1]);
        if(R<n)mx=max(mx,sufmx[R+1]),mn=min(mn,sufmn[R+1]);
        // cout<<wid<<" "<<L<<" "<<R<<" "<<mx<<" "<<mn<<endl;
        if((long long)mx-mn<=wid*2)return 1;
    }
    return 0;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>pt[i].first>>pt[i].second;
    for(int i=1;i<=n;++i)pt[i].first<<=1,pt[i].second<<=1;
    sort(pt+1,pt+1+n,[](const pair<int,int> &a,const pair<int,int> &b){return a.first-a.second<b.first-b.second;});
    // for(int i=1;i<=n;++i)cout<<pt[i].first<<pt[i].second;
    premn[1]=premx[1]=pt[1].first+pt[1].second;
    for(int i=2;i<=n;++i)premn[i]=min(premn[i-1],pt[i].first+pt[i].second),premx[i]=max(premx[i-1],pt[i].first+pt[i].second);
    sufmx[n]=sufmn[n]=pt[n].first+pt[n].second;
    for(int i=n-1;i>0;--i)sufmn[i]=min(sufmn[i+1],pt[i].first+pt[i].second),sufmx[i]=max(sufmx[i+1],pt[i].first+pt[i].second);

    // cout<<"after sorting: "<<endl;
    // for(int i=0;i<n;++i)cout<<pt[i].first<<" "<<pt[i].second<<endl;
    int L=0,R=2000000000,mid;
    while(R>L){
        mid=(L+R)>>1;
        if(check(mid))R=mid;
        else L=mid+1;
    }
    cout<<fixed<<setprecision(12)<<double(L)/2<<endl;
}
