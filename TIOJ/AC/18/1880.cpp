#include<bits/stdc++.h>
#define PB push_back
using namespace std;

int n,m;
vector<int> G[100005];
short gone[100005];

short dfs(int now,short type){
    gone[now]=type;
    for(int i=0;i<(int)G[now].size();i++){
        if(gone[G[now][i]]){
            if(gone[G[now][i]]==type)return -1;
        }
        else{
            if(dfs(G[now][i],-type)==-1){
                return -1;
            }
        }
    }
    return 1;
}

inline int _p(int base,int p){
    int ans=1;
    for(int i=1;i<=p;i++){
        ans = ans*2 % 1000007;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    while(m--){
        int p,q;
        cin>>p>>q;
        G[p].PB(q);
        G[q].PB(p);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!gone[i]){
            if(dfs(i,1)==-1){
                cout<<"0\n";
                return 0;
            }
            else{
                cnt++;
            }
        }
    }
    // cout<<"dfsa"<<endl;
    cout<<_p(2,cnt-1)<<endl;
}
