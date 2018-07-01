#include<bits/stdc++.h>
using namespace std;

vector<int> a[5],b[5];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        string s; cin>>s;
        a[s.size()].push_back(s.back());
    }
    for(int i=0;i<n;++i){
        string s; cin>>s;
        b[s.size()].push_back(s.back());
    }
    int ans=0;
    for(int i=2;i<=4;++i){
        sort(a[i].begin(),a[i].end());
        sort(b[i].begin(),b[i].end());
        for(int j=0;j<a[i].size();++j)if(a[i][j]!=b[i][j])++ans;
    }
    int s=0,m=0,l=0;
    for(int i:a[1]){
        if(i=='S')++s;
        if(i=='M')++m;
        if(i=='L')++l;
    }
    for(int i:b[1]){
        if(i=='S')--s;
        if(i=='M')--m;
        if(i=='L')--l;
    }
    ans+=(abs(s)+abs(m)+abs(l))>>1;
    cout<<ans<<endl;
}
