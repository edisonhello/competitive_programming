#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
int a[200005];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int mx=0,ed=-1;
    for(int i=1;i<=n;++i){
        auto it=mp.find(a[i]-1);
        int v=1;
        if(it!=mp.end())v=it->second+1;
        if(v>mx){
            mx=v;
            ed=a[i];
        }
        mp[a[i]]=v;

    }
    // cout<<"ed: "<<ed<<endl;
    cout<<mx<<endl;
    int st=ed-mx+1;
    for(int i=1;i<=n;++i){
        if(a[i]==st){
            cout<<i<<" ";
            ++st;
        }
    }
    cout<<endl;
}
