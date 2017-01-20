#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int main(){
    int n;cin>>n;
    int a[105],mx=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=mx-a[i];
    }
    cout<<ans<<endl;
}
