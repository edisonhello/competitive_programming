#include<iostream>
#define ll long long
using namespace std;
ll F[20];
inline void I(){
    F[1]=1;
    for(int i=2;i<20;i++){
        F[i]=F[i-1]*(4*i-2)/(i+1);
    }
    return;
}
int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    I();
    while(cin>>n){
        cout<<F[n]<<'\n';
    }
}
