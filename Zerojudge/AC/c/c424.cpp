// copy from TIOJ 1913
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,a[5005],ans;

inline void sol(){
    for(int i=1,mx,j;i<n;++i){
        mx=a[i];
        for(j=i+1;j<=n;++j){
            if(a[j]<a[i])break;
            mx=max(mx,a[j]);
            if(mx==a[j] && a[j]-a[i]==j-i){
                ++ans;
            }
        }
    }
}
int main(){
    int ts;scanf("%d",&ts);do{
        scanf("%d",&n);ans=0;
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        sol();
        reverse(a+1,a+1+n);
        sol();
        printf("%d\n",ans);
    }while(--ts);
}
