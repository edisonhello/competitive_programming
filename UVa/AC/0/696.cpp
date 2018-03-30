#include<bits/stdc++.h>
using namespace std;

int n,m;
int asz,nsz;
string mp[505],ans[505];

int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};

void dfs(int i,int j){
    if(j>=m)j=0,++i;
    if(i>=n){
        if(nsz>asz){
            asz=nsz;
            for(int i=0;i<n;++i)ans[i]=mp[i];
        }
        return;
    }
    bool put=1;
    for(int d=0;d<8;++d){
        int ii=i+dx[d],jj=j+dy[d];
        if(ii>=0 && jj>=0 && ii<n && jj<m && mp[ii][jj]=='X'){
            put=0;
            break;
        }
    }
    if(put){
        mp[i][j]='X';
        ++nsz;
        dfs(i,j+1);
        --nsz;
    }
    mp[i][j]='.';
    dfs(i,j+1);
}

int main(){
    // cin>>n>>m;
    /* for(int i=0;i<n;++i)for(int j=0;j<m;++j)mp[i]+=' ';
    dfs(0,0);
    for(int i=0;i<n;++i)cout<<ans[i]<<endl; */
    while(cin>>n>>m){
        if(n==0 && m==0)break;
        int ans;
        if(n==0 || m==0)ans=0;
        else if(n==1)ans=m;
        else if(m==1)ans=n;
        else if(n==2 || m==2){
            bool tag=0;
            if(n!=2)swap(n,m),tag=1;
            if(m==2 || m==3 || m==4)ans=4;
            else if(m%4==1)ans=(m/4-1)*4+6;
            else if(m%4==2)ans=(m/4+1)*4;
            else if(m%4==3)ans=(m/4+1)*4;
            else ans=m;
            if(tag)swap(n,m);
        }
        else{
            ans=0;
            for(int i=1;i<=n;++i){
                if(m%2==0)ans+=m/2;
                else ans+=m/2+(i&1);
            }
        }
        printf("%d knights may be placed on a %d row %d column board.\n",ans,n,m);
    }
}
