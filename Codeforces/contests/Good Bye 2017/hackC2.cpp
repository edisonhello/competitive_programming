#include<bits/stdc++.h>
using namespace std;

int save[1012];
double ans[1932];
int main(){
    int n,r; cin>>n>>r;
    for(int i=0;i<n;++i)cin>>save[i];
    ans[0]=r;
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            int dx=abs(save[i]-save[j]);
            if(dx<=2*r)ans[i]=max(ans[i],ans[j]+sqrt(4*r*r-(double)dx*dx));
        }
    }
    for(int i=0;i<n;++i)cout<<ans[i]<<" ";
}
