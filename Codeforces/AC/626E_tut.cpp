#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll x[200005],pre[200005];
int n;

ld get(int m,int l,int dlt){
    return (ld)(pre[n]-pre[n-l]+pre[m]-pre[m-1-l])/(l*2+dlt);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i];
    sort(x+1,x+n+1);
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+x[i];
    ld mxv=0;
    int mx_mid=1,slen=0;
    bool type2=0;

    for(int mid=1;mid<=n;++mid){
        int llen=mid-1,rlen=n-mid;
        int R=min(llen,rlen),a=0,step=1<<20;
        while(step>0){
            if(a+step<=R && get(mid,a+step,1)>get(mid,a+step-1,1))a+=step;
            step>>=1;
        }
        // cout<<mid<<" "<<a<<endl;
        if(mxv<get(mid,a,1)-x[mid]){
            mxv=get(mid,a,1)-x[mid];
            mx_mid=mid;
            slen=a;
        }
    }
    /* cout<<"mx_mid: "<<mx_mid<<" , slen: "<<slen<<" mxv: "<<mxv<<endl;
    cout<<(slen*2+(type2?2:1))<<endl;
    for(int i=mx_mid-1,j=0;j<slen;++j,--i)cout<<x[i]<<" ";
    for(int i=n,j=0;j<slen;++j,--i)cout<<x[i]<<" ";
    cout<<x[mx_mid]<<" ";
    if(type2)cout<<x[mx_mid+1]<<" ";
    cout<<endl; */
    for(int mid=1;mid<n;++mid){
        int llen=mid-1,rlen=n-mid-1;
        int R=min(llen,rlen),a=0,step=20;
        while(step>=0){
            if(a+(1<<step)<=R && get(mid,a+(1<<step),2)>get(mid,a+(1<<step)-1,2))a+=(1<<step);
            --step;
        }
        if(mxv<get(mid,a,2)-((ld)(x[mid]+x[mid+1]))/2){
            mxv=get(mid,a,2)-((ld)(x[mid]+x[mid+1]))/2;
            mx_mid=mid;
            slen=a;
            type2=1;
        }
    }
    
    // cout<<"mx_mid: "<<mx_mid<<" , slen: "<<slen<<" mxv: "<<mxv<<endl;
    cout<<(slen*2+(type2?2:1))<<endl;
    for(int i=mx_mid-1,j=0;j<slen;++j,--i)cout<<x[i]<<" ";
    for(int i=n,j=0;j<slen;++j,--i)cout<<x[i]<<" ";
    cout<<x[mx_mid]<<" ";
    if(type2)cout<<x[mx_mid+1]<<" ";
    cout<<endl;
}
