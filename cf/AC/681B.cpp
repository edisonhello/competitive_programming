#include<bits/stdc++.h>
using namespace std;

int t(long long n){
    if(n%1234==0)return 1;
    return 0;
}

int d(long long n){
    long long a=0,b=0;
    a=n/1234567;
    b=(n-(a*1234567))/123456;

    while(1){
        long long lft = n-(a*1234567+b*123456);
        if(t(lft)){
            // cout<<a<<" "<<b<<endl;
            return 1;
        }
        if(a==0&&b==0){
            // cout<<"jizzzzzzz";
            return 0;
        }

        if(b)b--;
        else{
            a--;
            b=(n-(a*1234567))/123456;
        }
    }
}

int main(){
    long long n;cin>>n;

    if(d(n)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}
