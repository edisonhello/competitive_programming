#include<bits/stdc++.h>
using namespace std;

int main(){
    double mx=1e15;
    int n,m; cin>>n>>m;
    while(n--){
        double a,b;  cin>>a>>b;
        mx=min(mx,a/b);
    }
    cout<<fixed<<setprecision(20)<<mx*m;
}
