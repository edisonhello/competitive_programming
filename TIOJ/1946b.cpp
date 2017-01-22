#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int a[1000006];
set<int> br[1000006];
vector<int> t;

int main(){
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cout<<"processing i="<<i<<endl;
        t.clear();
        for(int j=0;j<i;++j)if(a[j]>a[i])t.push_back(a[j]);
        sort(t.begin(),t.end());
        for(int i:t)cout<<i<<" ";cout<<endl;
        int L=t.size()?t[(t.size()-1)>>1]:999999;
        cout<<"get L="<<L<<endl;
        t.clear();
        for(int j=i+1;j<n;++j)if(a[j]>a[i])t.push_back(a[j]);
        sort(t.begin(),t.end());
        for(int i:t)cout<<i<<" ";cout<<endl;
        int R=t.size()?t[(t.size()-1)>>1]:999999;
        cout<<"get R="<<R<<endl;
        int num=min(L,R);
        br[i].insert(num);br[num].insert(i);
    }
    int ans=0;
    for(int i=0;i<n;++i)ans=max(ans,(int)br[i].size());
    cout<<ans<<endl;
}
