#include<bits/stdc++.h>
using namespace std;

int fail[122];
int dp[122][122][122];
struct {int x,y,z;} cf[122][122][122];

int main(){
    string s,t,u; cin>>s>>t>>u; 
    int n=s.size(),m=t.size(),k=u.size();
    s="$"+s+"@";
    t="#"+t+"@";
    u="*"+u+"*";
    [&](string &s){
        fail[1]=0;
        for(int i=2;i<=k;++i){
            int j=i-1;
            while(j>1 && s[fail[j]+1]!=s[i])j=fail[j];
            // if(s[fail[j]+1]==s[i])++j;
            fail[i]=(s[fail[j]+1]==s[i]?fail[j]+1:fail[j]);
            // cout<<"fail["<<i<<"]="<<fail[j]<<endl;
        }
        // for(int i=1;i<=k;++i)cout<<fail[i]<<" ";
    }(u);
    memset(dp,0xa0,sizeof(dp));
    dp[0][0][0]=0;
    auto up=[&](int v,int di,int dj,int dk,int si,int sj,int sk){
        if(v>=dp[di][dj][dk]){
            dp[di][dj][dk]=v;
            cf[di][dj][dk]={si,sj,sk};
        }
    };
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            for(int z=0;z<k;++z){
                // if(i==12 && j==17 && z==3)cout<<"now dp: "<<dp[i][j][z]<<endl;
                if(s[i+1]==t[j+1]){
                    if(s[i+1]==u[z+1]){
                        up(dp[i][j][z]+1,i+1,j+1,z+1,i,j,z);
                    }
                    else{
                        int t=fail[z];
                        while(t>=1 && s[i+1]!=u[t+1])t=fail[t];
                        int to=t+(s[i+1]==u[t+1]);
                        up(dp[i][j][z]+1,i+1,j+1,to,i,j,z);
                    }
                }
                up(dp[i][j][z],i,j+1,z,i,j,z);
                up(dp[i][j][z],i+1,j,z,i,j,z);
            }
        }
    }
    int mx=-1,mxk=-1;
    for(int z=0;z<k;++z){
        if(dp[n][m][z]>mx){
            mx=dp[n][m][z];
            mxk=z;
        }
    }
    if(mx<=0)exit((cout<<0<<endl,0));
    int i=n,j=m,z=mxk;
    stack<char> ans;
    while(i&&j){
        // cout<<"back trace: "<<i<<" "<<j<<" "<<z<<" has dp "<<dp[i][j][z]<<endl;
        if(cf[i][j][z].x!=i && cf[i][j][z].y!=j)ans.push(s[i]);
        tie(i,j,z)=make_tuple(cf[i][j][z].x,cf[i][j][z].y,cf[i][j][z].z);
    }
    while(ans.size()){
        cout<<ans.top();
        ans.pop();
    }
}
