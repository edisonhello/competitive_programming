#include<bits/stdc++.h>
using namespace std;



struct dmn{
    int x,h,i;
} a[100005];
int ans[100005];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].x>>a[i].h;
        a[i].i=i;
    }
    sort(a+1,a+n+1,[](const dmn &a,const dmn &b){return a.x>b.x;});
    stack<int> idx;
    for(int i=1;i<=n;++i){
        ans[a[i].i]=1;
        while(idx.size() && a[i].x+a[i].h>a[idx.top()].x){
            ans[a[i].i]+=ans[a[idx.top()].i];
            idx.pop();
        }
        // cout<<i<<" "<<ans[a[i].i]<<endl;
        idx.push(i);
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<" "; cout<<endl;
}
