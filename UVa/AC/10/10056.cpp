#include<bits/stdc++.h>
using namespace std;
#define ld long double

int main(){
    int ts; cin>>ts; while(ts--){
        int n,i; ld p; cin>>n>>p>>i;
        if(abs(p)<1e-8)cout<<"0.0000"<<endl;
        else cout<<fixed<<setprecision(4)<<p*pow(1-p,i-1)/(1-pow(1-p,n))<<endl;
    }
}
