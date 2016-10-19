#include<bits/stdc++.h>
using namespace std;

int a[1005],n,dpa[1005][1005];
bool v[1005][1005];

int dp(int l,int r){
    //cout<<"dp: "<<l<<" "<<r<<endl;
    if(l==r){
        //cout<<"get dp "<<l<<" "<<r<<" = "<<0<<endl;
        return 0;
    }
    if(v[l][r]){
        //cout<<"get dp "<<l<<" "<<r<<" = "<<dpa[l][r]<<endl;
        return dpa[l][r];
    }
    for(int i=l;i<r;++i){
        dpa[l][r]=max({/*dp(l,i)+dp(i+1,r)+(a[i]-a[l-1])*(a[r]-a[i]),*/
                               dp(i+1,r)+(a[i]-a[l-1])*(a[r]-a[i]),
                       dp(l,i)          +(a[i]-a[l-1])*(a[r]-a[i]),
                       dpa[l][r]});
    }
    v[l][r]=1;
    //cout<<"get dp "<<l<<" "<<r<<" = "<<dpa[l][r]<<endl;
    return dpa[l][r];
}

int bs(int n){
    if(n==1)return 0;
    if(n==0)return 0;
    return bs(n/2)*bs(n-n/2);
}

int A1(int n){
    // int m=(l+r)/2;
    // cout<<"all 1!"<<endl;
    return max((n-1)*n/2,bs(n));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    bool all1=1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]!=1)all1=0;
        // a[i]=3;
        a[i]+=a[i-1];
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            dpa[i][j]=0x80000000;
        }
    }
    if(all1)cout<<A1(n)<<'\n';
    else cout<<dp(1,n)<<'\n';

    /*cout<<"dpa:"<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<dpa[i][j]<<" ";
        }
        cout<<endl;
    }*/
}
