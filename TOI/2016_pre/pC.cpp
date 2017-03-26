#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int ind[2000];
bool G[2000][2000];
string a[100005];
queue<char> ans;

void dfs(int s,int t,int idx){
    while((int)a[s].length()<=idx && s<t)++s;
    if(s>=t)return;
    // cout<<"int dfs "<<s<<" "<<t<<" "<<idx<<endl;
    int i,j;
    for(i=s,j=s;i<t;++i){
        if(a[i][idx]!=a[i+1][idx]){
            if(!G[a[i][idx]][a[i+1][idx]]){++ind[a[i+1][idx]];/*cout<<s<<" "<<t<<" "<<i<<" "<<idx<<" "<<a[i][idx]<<endl;*/}
            G[a[i][idx]][a[i+1][idx]]=1;
            dfs(j,i,idx+1);
            j=i+1;
        }
    }
    dfs(j,t,idx+1);
}

int main(){
    int n;while(cin>>n,n){
        memset(G,0,sizeof(G));
        memset(ind,-1,sizeof(ind));
        for(int i=0;i<n;++i){
            cin>>a[i];
            for(auto &c:a[i])ind[c]=0;
            if(i && a[i]==a[i-1]){--i,--n;}
        }
        dfs(0,n-1,0);
        // for(int i='W';i<='Z';++i){
        //     for(int j='W';j<='Z';++j){
        //         cout<<G[i][j]<<" ";
        //     }cout<<endl;
        // }cout<<endl;
        // for(int i='W';i<='Z';++i){
        //     cout<<ind[i]<<" ";
        // }cout<<endl<<endl;
        // int cnt=0;
        while(1){
            // ++cnt;
            // if(cnt>5)break;
            // for(int i='W';i<='Z';++i){
            //     for(int j='W';j<='Z';++j){
            //         cout<<G[i][j]<<" ";
            //     }cout<<endl;
            // }cout<<endl;
            // for(int i='W';i<='Z';++i){
            //     cout<<ind[i]<<" ";
            // }cout<<endl<<endl;
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
}
