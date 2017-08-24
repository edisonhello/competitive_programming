#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;int now=0;int mx=-9898;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        now-=a;now+=b;
        mx = max(now,mx);
    }cout<<mx<<endl;
}
