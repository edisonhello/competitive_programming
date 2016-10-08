#include<bits/stdc++.h>
#define m (l+r)/2
using namespace std;
int n,k;
int s[20005],tot[20005];
int f[20005],b[20005];
int tf[20005],tb[20005];
int cal(int l,int r,int v){
    if(l==r){
        f[l]=b[l]=s[l];
        return (s[l]>v?1:0);
    }
    int now=cal(l,m,v)+cal(m+1,r,v);
    {
        int lptr=m,rptr=m+1;
        for(;rptr<=r;rptr++){
            // cout<<"rptr:"<<rptr<<", lptr:"<<lptr<<endl;
            while(lptr>=l && b[lptr]+f[rptr]<=v){
                lptr--;
                // cout<<"rptr:"<<rptr<<", lptr:"<<lptr<<endl;
            }
            now+=lptr-l+1;
            // cout<<"now+="<<lptr-l+1<<endl;
        }
    }
    // if(l==0 && r==4){
    //     cout<<"f: ";
    //     for(int i=0;i<5;i++){
    //         cout<<f[i]<<" ";
    //     }
    //     cout<<"\nb: ";
    //     for(int i=0;i<5;i++){
    //         cout<<b[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    {
        int lptr=l,rptr=m+1,ptr=l;
        while(lptr<=m&&rptr<=r){
            if(f[lptr]>f[rptr]+tot[m]-(l-1<0?0:tot[l-1])){
                tf[ptr++]=f[lptr++];
            }
            else{
                tf[ptr++]=f[rptr++]+tot[m]-(l-1<0?0:tot[l-1]); // SF l-1!
            }
        }
        while(lptr<=m){
            tf[ptr++]=f[lptr++];
        }
        while(rptr<=r){
            tf[ptr++]=f[rptr++]+tot[m]-(l-1<0?0:tot[l-1]); // SF l-1!
        }
        for(int i=l;i<=r;i++){
            f[i]=tf[i];
        }
    }
    {
        int lptr=l,rptr=m+1,ptr=l;
        while(lptr<=m&&rptr<=r){
            if(b[lptr]+tot[r]-tot[m]>b[rptr]){
                tb[ptr++]=b[lptr++]+tot[r]-tot[m];
            }
            else{
                tb[ptr++]=b[rptr++];
            }
        }
        while(lptr<=m){
            tb[ptr++]=b[lptr++]+tot[r]-tot[m];
        }
        while(rptr<=r){
            tb[ptr++]=b[rptr++];
        }
        for(int i=l;i<=r;i++){
            b[i]=tb[i];
        }
    }
    // cout<<"l="<<l<<" r="<<r<<" v="<<v<<" now="<<now<<endl;
    return now;
}
int CHK(int v){
    return cal(0,n-1,v)>k-1;
}
int BS(int l,int r){
    // cout<<"bs:"<<l<<" "<<r<<" "<<m<<endl;
    if(l>=r-1){
        return r;
    }
    bool res=CHK(m);
    if(res){
        return BS(m,r);
    }
    else{
        return BS(l,m);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    while(cin>>n>>k,n){
        int mx=-(1<<30),curx=0;
        int mn= (1<<30),curn=0;
        for(int i=0;i<n;i++){
            cin>>s[i];
            tot[i]=tot[i-1]+s[i];
            curx+=s[i];
            mx=max(mx,curx);
            if(curx<0)curx=0;
            curn+=s[i];
            mn=min(mn,curn);
            if(curn>0)curn=0;
        }
        cout<<BS(mn-99,mx+99)<<endl;
    }
}
