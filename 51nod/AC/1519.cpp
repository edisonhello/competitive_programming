#include<bits/stdc++.h>
using namespace std;

int a[100005],cl[100005];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cl[i]=a[i];
    int mn=0;
    for(int i=1;i<=n;++i){
        ++mn;
        mn=min(mn,a[i]);
        cl[i]=min(mn,cl[i]);
    }
    mn=0;
    for(int i=n;i>=1;--i){
        ++mn;
        mn=min(mn,a[i]);
        cl[i]=min(mn,cl[i]);
    }
    mn=0;
    for(int i=1;i<=n;++i)mn=max(mn,cl[i]);
    cout<<mn<<endl;
}
