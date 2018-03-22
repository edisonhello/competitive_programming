#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#define lb(x) ((x)&-(x))
using namespace std;

int a[22][22],n,atpos[1<<22],lg2[1<<22];
vector<int> ok_sit;
int dp[22][47000],prv,val,i_ptr;

void dfs(int now,int ptr,int mask){
    if(ptr<0){
        dp[i_ptr][atpos[now]]=max(dp[i_ptr][atpos[now]],val);
        return;
    }
    dfs(now,ptr-1,mask>>1);
    if(!(prv&mask) && !(now&(1<<(ptr+1))))dfs(now|(1<<ptr),ptr-1,mask>>1);
}

int main(){
    cin>>n;
    // int n=22;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>a[i][j];
    // for(int i=0;i<n;++i)for(int j=0;j<n;++j)a[i][j]=1;
    for(int i=2;i<(1<<n);++i)lg2[i]=lg2[i/2]+1;
    for(int i=0;i<(1<<n);++i){
        bool ok=1;
        for(int j=1;j<n;++j){
            if(i&(1<<(j-1)) && i&(1<<j)){
                ok=0;
                break;
            }
        }
        if(ok)ok_sit.push_back(i);
    }
    for(int i=0;i<ok_sit.size();++i)atpos[ok_sit[i]]=i;
    for(int j:ok_sit){
        for(int k=0;k<n;++k){
            if((1<<k)&j){
                dp[0][atpos[j]]+=a[0][k];
            }
        }
    }
    for(int i=1;i<n;++i){
        for(int j:ok_sit){
            prv=j;
            val=dp[i-1][atpos[j]];
            i_ptr=i;
            dfs(0,n-1,7<<max(0,n-2));
        }
        for(int j:ok_sit){
            int jj=j;
            while(jj){
                dp[i][atpos[j]]+=a[i][lg2[lb(jj)]];
                jj-=lb(jj);
            }
            /* for(int k=0;k<n;++k){
                if((1<<k)&j){
                    dp[i][atpos[j]]+=a[i][k];
                }
            } */
        }
    }
    int mx=0;
    for(int i=0;i<47000;++i)mx=max(mx,dp[n-1][i]);
    cout<<mx<<endl;
}
