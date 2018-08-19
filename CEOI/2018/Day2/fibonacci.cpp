#include<bits/stdc++.h>
using namespace std;

int fib[222];

int ans;
vector<vector<int>> all;
vector<int> cur;

void dfs(int ptr,int now){
    if(now==0){ ++ans; all.push_back(cur); return; }
    if(fib[ptr]>now)return;
    dfs(ptr+1,now);
    cur.push_back(fib[ptr]);
    dfs(ptr+1,now-fib[ptr]);
    cur.pop_back();
}

int sol(int n){
    ans=0;
    all.clear();
    dfs(1,n);
    return ans;
}


void init(){
    fib[0]=fib[1]=1;
    for(int i=2;i<=100;++i)fib[i]=fib[i-1]+fib[i-2];
    for(int i=1;i<=50;++i){
        cout<<"F("<<i<<"): "<<sol(i)<<" -- ";
        /* for(auto v:all){
            cout<<"[";
            for(int i:v)cout<<i<<" ";
            cout<<"] ";
        } */
        cout<<endl;
    }
}

int a[100005];
int main(){
    init();
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    int now=0;
    for(int i=1;i<=n;++i)now+=fib[a[i]],cout<<sol(now)<<'\n';
}
