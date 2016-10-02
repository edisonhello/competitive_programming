#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[555];
ll gcd(ll a,ll b){
    if(b>a)swap(a,b);
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
int main(){
    int n;
    while(cin>>n){
        ll G;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i){
                G=gcd(G,a[i]);
            }
            else{
                G=a[i];
            }
        }
        cout<<G<<'\n';
    }
}
