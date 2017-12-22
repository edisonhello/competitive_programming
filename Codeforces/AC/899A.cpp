#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int c1=0,c2=0;
    while(n--){
        int t; cin>>t;
        if(t==1)++c1;
        else ++c2;
    }
    int ans=min(c1,c2);
    c1-=ans,c2-=ans;
    cout<<ans+c1/3<<endl;
}
