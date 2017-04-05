#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int ind[2000];
bool G[2000][2000];
string a[100005];
queue<char> ans;

void dfs(int s,int t,int idx){
    // cout<<s<<" "<<t<<" "<<idx<<endl;
    while((int)a[s].length()<=idx && s<t)++s;
    if(s>=t)return;
    // cout<<"int dfs "<<s<<" "<<t<<" "<<idx<<endl;
    int i,j;
    for(i=s,j=s;i<t;++i){
        if(a[i][idx]!=a[i+1][idx]){
            if(!G[a[i][idx]][a[i+1][idx]]){
                ++ind[a[i+1][idx]];
                G[a[i][idx]][a[i+1][idx]]=1;
            }
            dfs(j,i,idx+1);
            j=i+1;
        }
    }
    dfs(j,t,idx+1);
}

int main(){
    memset(G,0,sizeof(G));
    memset(ind,-1,sizeof(ind));
    int n=0;
    string s; while(cin>>s){
        if(s!="#")a[n]=s;
        else break;
        for(auto &c:a[n])ind[c]=0;
        if(n && a[n]==a[n-1]){--n;}
        ++n;
    }
    dfs(0,n-1,0);
    // for(int i='W';i<='Z';++i){
    //     for(int j='W';j<='Z';++j)cout<<G[i][j]<<" ";cout<<endl;
    // }cout<<endl;
    while(1){
        bool sth=0;
        for(int i=0;i<200;++i){
            if(!~ind[i])continue;
            if(ind[i])++sth;
            else{
                for(int j=0;j<200;++j){
                    if(G[i][j]){--ind[j];}
                }
                ind[i]=-1;
                ans.push(i);
            }
        }
        if(!sth)break;
    }
    while(ans.size()){
        cout<<ans.front();
        ans.pop();
    }cout<<endl;
}
