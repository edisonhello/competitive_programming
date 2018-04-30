#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[50005];
ll dp[50005][6][12];

int cti[222];
char itc[10]={0,'A','C','G','T'};

vector<int> ans;

void dfs(int now,int len,int type,ll lim){
    // cout<<now<<" "<<type<<" "<<lim<<endl;
    if(now>len){
        for(int i=1;i<ans.size();++i)cout<<itc[ans[i]]; cout<<endl;
        exit(0);
    }
    ll c=0;
    for(int u=1;u<=4;++u){
        int nt=type-(u<ans.back());
        if(c+dp[now][u][nt]>=lim){
            ans.push_back(u);
            // cout<<"use "<<u<<endl;
            dfs(now+1,len,nt,lim-c);
        }
        else c+=dp[now][u][nt];
    }
}

int main(){
    int m,k; ll r; cin>>m>>k>>r;
    string s; cin>>s;
    cti['A']=1; cti['C']=2; cti['G']=3; cti['T']=4; cti['N']=0;
    for(int i=0;i<m;++i)a[i+1]=cti[s[i]];
    // dp[m+1][4][1]=1;
    for(int i=1;i<=k;++i)dp[m+1][4][i]=1;
    for(int i=m;i>=1;--i){
        for(int u=1;u<=4;++u){
            if(a[i] && a[i]!=u)continue;
            for(int t=1;t<=k;++t){
                for(int p=1;p<=4;++p){
                    int y=t-(u>p);
                    dp[i][u][t]+=dp[i+1][p][y];
                }
            }
        }
    }
    /* for(int i=1;i<=m;++i){
        for(int u=1;u<=4;++u){
            for(int t=1;t<=k;++t){
                cout<<"dp["<<i<<"]["<<u<<"]["<<t<<"]="<<dp[i][u][t]<<endl;
            }
        }
    } */
    ans.push_back(0);
    dfs(1,m,k,r);
}
