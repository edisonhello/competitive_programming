#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<string>
#include<sstream>
#include<iomanip>
#include<cstring>
using namespace std;

int n,c[100005],leaf=1,root;
vector<int> G[100005];
bool pos=1;

void gotoLeaf(int now,int p){
    for(int &i:G[now]){
        if(i==p)continue;
        gotoLeaf(i,now);
        return;
    }
    leaf=root=now;
}

int d2(int now,int p,int col){
    if(c[now]!=col)return 1;
    for(int &i:G[now]){
        if(i==p)continue;
        if(d2(i,now,col))return 1;
    }
    return 0;
}

int dfs(int now,int p,int col){
    if(c[now]!=col){
        for(int &i:G[now]){
            if(d2(i,now,c[i])){
                pos=0;
                break;
            }
        }
        root=now;
        return 1;
    }
    for(int &i:G[now]){
        if(i==p)continue;
        if(dfs(i,now,col)){
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;++i){
        int s,t;cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    for(int i=1;i<=n;++i){
        cin>>c[i];
    }


    gotoLeaf(leaf,leaf);
    cout<<"lf "<<leaf<<endl;

    // memset(v,0,sizeof(v));
    dfs(leaf,leaf,c[leaf]);

    if(!pos)cout<<"NO\n";
    else cout<<"YES\n"<<root<<endl;
}
// WA code but Codeforces gives AC
// Submission 24377428
// Input
// 5
// 1 2
// 2 3
// 2 4
// 2 5
// 2 1 1 2 2
// Output
// NO
// Answer
// YES
// 2
