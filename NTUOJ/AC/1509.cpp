#include<bits/stdc++.h>
using namespace std;

int a[104][104],b[104][104];

int main(){
    int t,zz=0; scanf("%d",&t); while(t--){
        printf("Case %d: ",++zz);
        int n,k; scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)scanf("%d",&a[i][j]);
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)scanf("%d",&b[i][j]);
        bool same=1;
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(a[i][j]!=b[i][j])same=0;
        if(same){ puts("0"); continue; }
        bool sym=1;
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(b[i][j]!=b[j][i])sym=0;
        if(sym){ puts("-1"); continue; }

        int needch=0;
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(a[i][j]!=b[i][j])needch++;

        int dia=0;
        for(int i=0;i<n;++i)if(a[i][i]!=b[i][i])++dia;
        needch-=dia;

        int swap=0;
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(a[i][j]!=b[i][j] && a[j][i]!=b[j][i] && a[i][j]==b[j][i] && a[j][i]==b[i][j])++swap;
        swap>>=1;

        if(needch==2 && swap==1){
            if(n==2 && k==2)puts("-1");
            else if(k==2)printf("%d\n",4+dia);
            else printf("%d\n",3+dia);
        }
        else printf("%d\n",needch+dia);
    }
}
