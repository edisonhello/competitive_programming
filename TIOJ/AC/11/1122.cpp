#include<bits/stdc++.h>
using namespace std;
int a[22][22],m[22],i,j,k,mx,now,n,a11;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n>>a11){
        memset(a,0,sizeof(a));
        a[1][1]=a11;
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j){
                if(i==1&&j==1)continue;
                a[i][j]=(j==1?a[1][1]+i:a[i][j-1]*17%103*((i+j)&1?-1:1));
            }
        }
        mx=0;
        for(i=1;i<=n;++i){
            memset(m,0,sizeof(m));
            for(j=i;j<=n;++j){
                now=0;
                for(k=1;k<=n;++k){
                    m[k]+=a[j][k];
                    now+=m[k];
                    if(now<0)now=0;
                    mx=max(mx,now);
                }
            }
        }
        cout<<mx<<'\n';
    }
}
