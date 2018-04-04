#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[3003],b[3003];
bitset<3003> v[3003];
ll rec[3003][3003];

ll dfs(int ptr,int mx){
    if(mx<=0)return 1ll<<60;
    if(ptr==1)return min(dfs(ptr,mx-1),(ll)abs(a[ptr]-b[mx]));
    if(v[ptr][mx])return rec[ptr][mx];
    v[ptr][mx]=1;
    return rec[ptr][mx]=min(dfs(ptr-1,mx)+abs(a[ptr]-b[mx]),dfs(ptr,mx-1));
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],a[i]-=i,b[i]=a[i];
    sort(b+1,b+1+n);
    cout<<dfs(n,n)<<endl;
}
