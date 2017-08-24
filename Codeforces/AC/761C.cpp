#include<iostream>
using namespace std;
#include<cstring>
#include<algorithm>

struct st{int v,i,t;};
bool operator<(const st &a,const st &b){return a.v<b.v;}
bool operator>(const st &a,const st &b){return a.v>b.v;}

int n,m,dis[5][55];
string s[55];

int dfs3(int i,int j){
    int mn=0x22222222;
    for(int k=0;k<n;++k){
        if(i==k)continue;
        if(j==k)continue;
        mn=min(mn,dis[2][k]);
    }
    return mn;
}
int dfs2(int i){
    int mn=0x22222222;
    for(int j=0;j<n;++j){
        if(i==j)continue;
        mn=min(mn,dis[1][j]+dfs3(i,j));
    }
    return mn;
}
int dfs1(){
    int mn=0x22222222;
    for(int i=0;i<n;++i){
        mn=min(mn,dis[0][i]+dfs2(i));
    }
    return mn;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>s[i];
    memset(dis,0x22,sizeof(dis));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(s[i][j]>='0' && s[i][j]<='9'){
                dis[0][i]=min({dis[0][i],j,m-j});
            }
            else if(s[i][j]>='a' && s[i][j]<='z'){
                dis[1][i]=min({dis[1][i],j,m-j});
            }
            else{
                dis[2][i]=min({dis[2][i],j,m-j});
            }
        }
    }
    cout<<dfs1()<<endl;
}
