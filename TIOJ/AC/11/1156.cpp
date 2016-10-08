#include<bits/stdc++.h>
using namespace std;
int a[555];
int gcd(int a,int b){
    if(b>a)swap(a,b);
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
int main(){
    int n;cin>>n;
    int G;
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
