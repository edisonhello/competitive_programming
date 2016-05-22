#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<int>p;
    for(int i=0;i<m;i++){
        int t;cin>>t;p.push_back(t);
    }
    sort(p.begin(),p.end());
    int mn=98797987;
    for(int i=0;i<m-n+1;i++){
        mn = min(mn,p[i+n-1]-p[i]);
    }
    cout<<mn<<endl;
}
