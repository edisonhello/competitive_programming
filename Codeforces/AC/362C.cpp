#pragma GCC optimize ("no-stack-protector")
#include<cstdio>
#include<algorithm>
using namespace std;


int a[5006],cnt[5006][5006];
int main(){
    int n; scanf("%d",&n);
    // int n; n=5000;
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        // a[i]=i;
        for(int j=0;j<n;++j)cnt[i][j]+=cnt[i-1][j];
        cnt[i][a[i]]++;
    }
    int ivp=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(a[i]>a[j])++ivp;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<n;++j){
            if(j)cnt[i][j]+=cnt[i][j-1];
            // printf("%d ",cnt[i][j]);
        }
    }
    int mn=1e9,wys=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            int xx=max(a[i],a[j]),nn=min(a[i],a[j]);
            int dta=(a[i]<a[j]?1:-1)*(2*(cnt[j-1][xx-1]-cnt[i][xx-1]-cnt[j-1][nn]+cnt[i][nn])+1);
            // printf("%d %d %d %d\n",i,j,dta,(cnt[j-1][xx-1]-cnt[i][xx-1]-cnt[j-1][nn+1]+cnt[i][nn+1]));
            if(ivp+dta<mn){
                mn=ivp+dta;
                wys=1;
            }
            else if(ivp+dta==mn){
                ++wys;
            }
        }
    }
    printf("%d %d\n",mn,wys);
}
