#include<bits/stdc++.h>
using namespace std;

int i,j,k,rn,cn;
int a[52][52],ans,now,mx,rr[52][52];
bool take;

inline void t(int &x,int &y){
    now=0,mx=0,take=0;
    for(k=1;k<=cn;k++){
        now+=(rr[y][k]-rr[x-1][k]);
        take=1;
        ans=max(ans,now);
        if(now<0){
            now=0;
            take=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>rn>>cn){
        memset(a,0,sizeof(a));
        memset(rr,0,sizeof(rr));
        ans=now=mx=0;
        for(i=1;i<=rn;i++){
            for(j=1;j<=cn;j++){
                cin>>a[i][j];
                for(k=1;k<=i;k++){
                    rr[i][j]+=a[k][j];
                }
            }
        }
        ans=a[1][1];
        for(i=1;i<=rn;i++){
            for(j=i;j<=rn;j++){
                t(i,j);
            }
        }
        cout<<ans<<endl;
    }
}
