#include<bits/stdc++.h>


#define ll long long

using namespace std;
int fac5(ll n)
{
    int cnt=0;
    while(n%5==0){
        cnt++;
        n/=5;
    }
    return cnt;
}

int main(){
    int n;cin>>n;
    int cnt=0;
    int i;
    for(i=5;;i+=5){
        cnt+=fac5(i);
        if(cnt>n){
            cout<<0<<endl;
            return 0;
        }
        if(cnt==n){
            break;
        }
    }
    cout<<"5"<<endl;
    cout<<i<<" "<<i+1<<" "<<i+2<<" "<<i+3<<" "<<i+4<<endl;
}
