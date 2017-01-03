#include<cstdio>
#include<cstring>
using namespace std;

int a[100005];

int main(){
    int ts;scanf("%d",&ts);while(ts--){
        bool jizz=0;
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=100000;++i)a[i]=-9999999;
        for(int i=0,t;i<n;++i){
            scanf("%d",&t);
            if(i-a[t]<=k)jizz=1;
            a[t]=i;
        }
        if(jizz)puts("No");
        else puts("Yes");
    }
}
