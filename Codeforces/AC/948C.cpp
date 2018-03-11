#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,dead[100005];
ll v[100005],t[100005],delta[100005];
int main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>v[i];
    for(int i=0;i<n;++i)cin>>t[i],i?t[i]+=t[i-1]:0;
    for(int i=0;i<n;++i){
        auto it=lower_bound(t,t+n,v[i]+(i?t[i-1]:0));
        if(it==t+n)continue;
        delta[it-t]+=(*it)-(v[i]+(i?t[i-1]:0));
        ++dead[it-t+1];
    }
    int alive=0;
    for(int i=0;i<n;++i){
        alive-=dead[i]; ++alive;
        cout<<(t[i]-(i?t[i-1]:0))*alive-delta[i]<<" ";
    } cout<<endl;
}
