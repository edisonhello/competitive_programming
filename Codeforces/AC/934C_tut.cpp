#include<bits/stdc++.h>
using namespace std;

int n,a[2345],pre1[2345],pre2[2345];

int c1(int l,int r){
    if(l>r || r<1 || l>n)return 0;
    return pre1[r]-pre1[l-1];
}
int c2(int l,int r){
    if(l>r || r<1 || l>n)return 0;
    return pre2[r]-pre2[l-1];
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)pre1[i]=pre1[i-1]+(a[i]==1);
    for(int i=1;i<=n;++i)pre2[i]=pre2[i-1]+(a[i]==2);
    int ans=0;
    for(int i=0;i<=n;++i){
        ans=max(ans,c1(1,i)+c2(i+1,n));
    }
    for(int i=1;i<=n;++i){
        int lp=0,rp=0;
        for(int j=0;j<=i;++j){
            lp=max(lp,c1(1,j)+c2(j+1,i));
        }
        for(int j=i;j<=n;++j){
            rp=max(rp,c1(i+1,j)+c2(j+1,n));
        }
        ans=max(ans,lp+rp);
    }
    cout<<ans<<endl;
}
