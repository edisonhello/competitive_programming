#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005],cnt[100005];
bool p[100005];
int main(){
    int n;scanf("%d",&n);

    int mxans=1; p[0]=p[1]=1;
    for(int i=2;i<100004;++i){
        if(p[i])continue;
        for(int j=i*i;j<100004;j+=i){
            if(!(i<1000))break;
            p[j]=1;
        }
    }

    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        if(!p[a[i]])++cnt[a[i]];
        else{
            for(int j=2;j<=a[i];++j){
                if(p[j])continue;
                if(a[i]%j)continue;
                while(!(a[i]%j))a[i]/=j;
                ++cnt[j];
                if(!p[a[i]]){++cnt[a[i]];break;}
            }
        }
    }
    int mx=1;
    for(int i=1;i<100004;++i){
        mx=max(mx,cnt[i]);
    }
    printf("%d\n",mx);
}
