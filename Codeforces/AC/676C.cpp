#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,now; cin>>n>>k; now=k;
    string s; cin>>s;
    int L=0,R=-1;
    int ans=0;
    while(R<n-1){
        ++R;
        if(s[R]=='b')--now;
        while(now<0){
            if(s[L]=='b')++now;
            ++L;
        }
        ans=max(ans,R-L+1);
    }
    now=k,L=0,R=-1;
    while(R<n-1){
        ++R;
        if(s[R]=='a')--now;
        while(now<0){
            if(s[L]=='a')++now;
            ++L;
        }
        ans=max(ans,R-L+1);
    }
    cout<<ans<<endl;
}
