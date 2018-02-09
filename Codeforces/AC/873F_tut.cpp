#include<bits/stdc++.h>
using namespace std;

#define left siefjojoij
#define right oaidigijo

struct meow{
    int r,x,y,i;
} a[200007];
int pos[200007],lcpa[200007],forpre[200007],left[200007],right[200007];

int L(int idx,int x){if(idx==-1)return idx; return lcpa[idx]<x?idx:L(left[idx],x);}
int R(int idx,int x){return lcpa[idx]<x?idx:R(right[idx],x);}

int main(){
    int n; cin>>n;
    string s; cin>>s;
    string forbid; cin>>forbid;
    reverse(s.begin(),s.end());
    reverse(forbid.begin(),forbid.end());
#ifdef WEAK
    cout<<"s     : "<<s<<endl;
    cout<<"forbid: "<<forbid<<endl;
#endif
    for(int i=0;i<n;++i)a[i]={0,s[i],0,i};
    auto cmp_xy=[](const meow &a,const meow &b){return a.x==b.x?a.y<b.y:a.x<b.x;};
    sort(a,a+n,cmp_xy);
    for(int D=1;D<n;D<<=1){
        for(int i=0,r=1;i<n;++i)pos[a[i].i]=i,a[i].r=(i&&(a[i].x!=a[i-1].x||a[i].y!=a[i-1].y)?++r:r);
        for(int i=0;i<n;++i)a[i].y=(a[i].i+D>=n?0:a[pos[a[i].i+D]].r),a[i].x=a[i].r;
        sort(a,a+n,cmp_xy);
    }
    // for(int i=0;i<n;++i)cout<<a[i].i<<" "; cout<<endl;
    int lcpl=0;
    for(int i=0;i<n;++i)pos[a[i].i]=i;
    for(int i=0;i<n;++i,--lcpl){
        if(pos[i]==n-1)continue;
        lcpl=max(lcpl,0);
        while(lcpl>0 && (a[pos[i]].i+lcpl>s.size() || a[pos[i]+1].i+lcpl>s.size()))--lcpl;
        while(a[pos[i]].i+lcpl<s.size() && a[pos[i]+1].i+lcpl<s.size() && s[a[pos[i]].i+lcpl]==s[a[pos[i]+1].i+lcpl])++lcpl;
        // if(i==1)cout<<s[a[i].i+lcpl]<<" & "<<s[a[pos[a[i].i]+1].i+lcpl]<<endl;
        lcpa[pos[i]]=lcpl;
    }
    // for(int i=0;i<n;++i)cout<<lcpa[i]<<" "; cout<<endl;
    long long ans=0,mx=0;
    // cout<<"do LR"<<endl;
    left[0]=-1; for(int i=0;i<n;++i)left[i]=L(i-1,lcpa[i]);
    // cout<<"L"<<endl;
    // for(int i=0;i<n;++i)cout<<left[i]<<" "; cout<<endl;

    lcpa[n]=-1;
    for(int i=n-1;i>=0;--i)right[i]=R(i+1,lcpa[i]);
    // for(int i=0;i<n;++i)cout<<right[i]<<" "; cout<<endl;


    for(int i=0;i<=n;++i)forpre[i]=(i?forpre[i-1]:0)+(forbid[a[i].i]=='1');
    for(int i=0;i<n;++i)ans=max(ans,1ll*(right[i]-left[i]-(forpre[right[i]]-(left[i]==-1?0:forpre[left[i]])))*lcpa[i]);
    for(int i=0;i<n;++i)if(forbid[i]!='1')mx=max(mx,(long long)n-i);
    cout<<max(ans,mx)<<endl;

    /* stack<int> st;
    for(int i=0;i<n;++i){
        if(forbid[i]=='1'){++forpre[i];} if(i)forpre[i]+=forpre[i-1];
        int x=lcpa[i];
        // cout<<"now at "<<i<<" val: "<<x<<endl;
        while(st.size() && lcpa[st.top()]>x){
            ans=max(ans,1ll*lcpa[st.top()]*(i-st.top()+1-(forpre[i]-(st.top()?forpre[st.top()-1]:0))));
            // cout<<"curans: "<<1ll*lcpa[st.top()]*(i-st.top()+1-(forpre[i]-(st.top()?forpre[st.top()-1]:0)))<<endl;
            // cout<<"distance: "<<i-st.top()+1<<endl;
            // cout<<"forbid: "<<(forpre[i]-(st.top()?forpre[st.top()-1]:0))<<endl;
            st.pop();
        }
        if(forbid[i]!='1')st.push(i);
    }
    // cout<<"out for"<<endl;
    while(st.size()){
        ans=max(ans,1ll*(n-1-st.top()-(forpre[n-1]-(st.top()?forpre[st.top()-1]:0))));
        st.pop();
    }
    // cout<<"tmpans: "<<ans<<endl;
    long long mx=0;
    for(int i=0;i<n;++i)if(forbid[i]!='1')mx=max(mx,(long long)n-i);
    cout<<max(ans,mx)<<endl; */
}
