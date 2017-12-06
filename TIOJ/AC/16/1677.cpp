#include<bits/stdc++.h>
using namespace std;


void construct(bool rev=0,int mxlen=100){
    if(rev){
        string s="G",ss;
        while(s.length()<mxlen){
            reverse(s.begin(),s.end());
            cout<<s<<endl;
            reverse(s.begin(),s.end());
            ss="";
            for(char c:s){
                if(c=='G')ss+="Y";
                else ss+="GY";
            }
            s=ss;
        }
    }
    else{
        string s="G",ss;
        while(s.length()<mxlen){
            cout<<s<<endl;
            ss="";
            for(char c:s){
                if(c=='G')ss+="Y";
                else ss+="GY";
            }
            s=ss;
        }
    }
}
long long fib[122];
int solve(int n,long long k){
    if(n<=2 && k>1)return -1;
    else if(n<=2)return n-1;
    fib[1]=1;
    for(int i=2;i<=n;++i){
        fib[i]=fib[i-1]+fib[i-2];
        if(i==n && fib[i]<k)return -1;
        else if(fib[i]>5000000000ll)break;
    }
    while(n>2){
        if(k<=fib[n-2] || fib[n-2]==0)n-=2;
        else --n,k-=fib[n-1];
    }
    return n-1;
}
int main(){
    int m; cin>>m; while(m--){
        int n; long long k; cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
}
