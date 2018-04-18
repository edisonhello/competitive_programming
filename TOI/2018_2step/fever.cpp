#include<bits/stdc++.h>
using namespace std;

int a[1111],cnt[1111][5];
double ch[1111][5];

double be[111][111],st[111][111];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    ch[1][1]=1;
    cnt[1][1]=1;

    be[1][1]=0.7; be[1][2]=0.3;
    be[2][1]=0.4; be[2][2]=0.6;

    st[1][1]=0.5; st[1][2]=0.4; st[1][3]=0.1;
    st[2][1]=0.1; st[2][2]=0.3; st[2][3]=0.6;

    for(int i=2;i<=n;++i){
        if(ch[i-1][1]*0.7>ch[i-1][2]*0.4){
            ch[i][1]=ch[i-1][1]*0.7/(st[1][a[i]]+st[2][a[i]])*st[1][a[i]];
            cnt[i][1]=cnt[i-1][1]+1;
        }
        else{
            ch[i][1]=ch[i-1][2]*0.4/(st[1][a[i]]+st[2][a[i]])*st[1][a[i]];
            cnt[i][1]=cnt[i-1][2]+1;
        }
        if(ch[i-1][1]*0.3>ch[i-1][2]*0.6){
            ch[i][2]=ch[i-1][1]*0.3/(st[1][a[i]]+st[2][a[i]])*st[2][a[i]];
            cnt[i][2]=cnt[i-1][1];
        }
        else{
            ch[i][2]=ch[i-1][2]*0.6/(st[1][a[i]]+st[2][a[i]])*st[2][a[i]];
            cnt[i][2]=cnt[i-1][2];
        }
        double mn=min(ch[i][1],ch[i][2]);
        ch[i][1]/=mn;
        ch[i][2]/=mn;
    }
    if(ch[n][1]>ch[n][2])cout<<cnt[n][1]<<endl;
    else cout<<cnt[n][2]<<endl;
}
