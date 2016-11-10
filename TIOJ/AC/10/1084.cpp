#include<iostream>
#include<cstring>
#include<stack>
#define G(x,y) ((x)>(y)?g[y][x]:g[x][y])
using namespace std;
int n;
int g[555][555];
int deg[555];
stack<int> ans;

void dfs(int now){
    for(int i=0;i<521;++i){
        if(G(now,i)){
            --G(now,i);
            dfs(i);
        }
    }
    ans.push(now);
}

int main(){
    while(cin>>n,n){
        memset(g,0,sizeof(g));
        memset(deg,0,sizeof(deg));
        while(ans.size()){
            ans.pop();
        }
        for(int i=0,s,e;i<n;++i){
            cin>>s>>e;
            if(s>e)swap(s,e);
            ++g[s][e];
            ++deg[s];++deg[e];
        }
        for(int i=0;i<521;++i){
            if(deg[i]&1){
                dfs(i);
                goto getAns;
            }
        }
        for(int i=0;i<521;++i){
            if(deg[i]){
                dfs(i);
                goto getAns;
            }
        }
        getAns:;
        while(ans.size()){
            cout<<ans.top()<<endl;ans.pop();
        }
        cout<<endl;
    }
}
