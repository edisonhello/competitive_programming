#include<bits/stdc++.h>
using namespace std;
#define left isroroo
int left[555];

int pw(long long b,int n,long long m,long long a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a%m;
}

int main(){
    int n,m; long long mod;
    cin>>n>>m>>mod;
    for(int i=0;i<n;++i)left[i]=2;
    for(int i=0;i<m;i++){
        string s; cin>>s;
        for(int j=0;j<n;++j){
            if(s[j]=='1')--left[j];
        }
    }
    int cnt=0;
    // for(int i=0;i<n;++i)cnt+=left[i];
    cnt-=n-m;
    for(int i=0;i<n;++i)if(left[i]==2)--cnt;
    cout<<pw(2,cnt,mod)<<endl;
}
