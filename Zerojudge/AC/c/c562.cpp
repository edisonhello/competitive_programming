#include<bits/stdc++.h>
using namespace std;


int main(){
    long long n; while(cin>>n){
        if(n==0){cout<<1<<endl; continue;}
        int ans=0;
        while(n){
            int t=n%10; n/=10;
            if(t==0 || t==6 || t==9)++ans;
            if(t==8)ans+=2;
        }
        cout<<ans<<endl;
    }
}
