#include<bits/stdc++.h>
using namespace std;

vector<int> a,b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        a.resize(n);
        b.resize(m);
        for(int &i:a)cin>>i;
        for(int &i:b)cin>>i;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        while(a.size() && a.back()==0)a.pop_back();
        while(b.size() && b.back()==0)b.pop_back();
        if(a==b)cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
}
