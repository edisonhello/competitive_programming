#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,ans=0;cin>>n;

    for(int i=0;i<n;i++){
        string a;cin>>a;
        if(a.find("++")<50)ans++;
        else if(a.find("--")<50)ans--;
    }cout<<ans<<endl;
}
