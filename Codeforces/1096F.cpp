#include<bits/stdc++.h>
using namespace std;

int a[200005],bit[200005];

#define lb(x) ((x)&-(x))

int use[200005];
int b[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)if(a[i]>0)use[a[i]]=1;
    long long le=0;
    for(int i=1,j=1;i<=n;++i){
        if(a[i]>0)b[i]=a[i];
        else{
            while(use[j])++j;
            b[i]=j; ++j;
        }
    }
    for(int i=1;i<=n;++i){
        for(int x=b[i];x<200005;x+=lb(x))le+=bit[x];
        for(int x=b[i];x;x-=lb(x))bit[x]++;
    }
    memset(bit,0,sizeof(bit));
    memset(b,0,sizeof(b));
    long long ge=0;
    for(int i=1,j=n;i<=n;++i){
        if(a[i]>0)b[i]=a[i];
        else{
            while(use[j])--j;
            b[i]=j; --j;
        }
    }
    for(int i=1;i<=n;++i){
        for(int x=b[i];x<200005;x+=lb(x))ge+=bit[x];
        for(int x=b[i];x;x-=lb(x))bit[x]++;
    }
    cout<<(le+ge)%998244353*(998244354/2)%998244353<<endl;
}
