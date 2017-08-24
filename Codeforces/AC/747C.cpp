#include<cstdio>

using namespace std;

int m[105];
int main(){
    int n,q,t,k,d,a,nk;
    scanf("%d%d",&n,&q);
    while(q--){
        scanf("%d%d%d",&t,&k,&d);
        a=0;nk=0;
        for(int i=1;i<=n && nk<k;++i){
            if(m[i]<=t)++nk;
        }
        if(nk<k){
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n && k;++i){
            if(m[i]<=t){
                m[i]=t+d;
                --k;
                a+=i;
            }
        }
        printf("%d\n",a);
    }
}
