#include<bits/stdc++.h>
using namespace std;

int fail[1000006];
int main(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    fail[-1]=fail[0]=-1;
    for(int i=1;i<n;++i){
        int ptr=i-1;
        while(s[i]!=s[fail[ptr]+1] && ptr>0)ptr=fail[ptr];
        fail[i]=fail[ptr]+(s[i]==s[fail[ptr]+1]);
        // cout<<i<<" "<<ptr<<endl;
    }
    // for(int i=0;i<n;++i)cout<<fail[i]<<" "; cout<<endl;
    for(int i=0;i<n;++i){
        int le=i-fail[i];
        int cc=(i+1)/le;
        if((i+1)%le==0){
            if(cc/k-cc%k>=0)cout<<1;
            else cout<<0;
        }
        else{
            if(cc/k-cc%k>0)cout<<1;
            else cout<<0;
        }
    }
    cout<<endl;
}
