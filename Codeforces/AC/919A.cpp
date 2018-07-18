#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m; cin>>n>>m;
    double mn=1e10;
    while(n--){
        double a,b; cin>>a>>b;
        mn=min(mn,a/b);
    }
    cout<<fixed<<setprecision(10)<<m*mn<<endl;
}
