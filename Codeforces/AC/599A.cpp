#include<bits/stdc++.h>
using namespace std;

int main(){
    int d1,d2,d3; cin>>d1>>d2>>d3;
    int ans=d1*2+d2*2;
    ans=min(d1+d2+d3,ans);
    ans=min(2*(d1+d3),ans);
    ans=min(2*(d2+d3),ans);
    cout<<ans<<endl;
}
