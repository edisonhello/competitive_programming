#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; getchar(); while(t--){
        long long ans=0,O=0,w=0;
        char c;
        while((c=getchar())!='\n'){
            if(c=='O')ans=(ans+w)%1000000007,++O;
            else if(c=='w')w=(w+O)%1000000007;
        }
        cout<<ans<<endl;
    }
}
