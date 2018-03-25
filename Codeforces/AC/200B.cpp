#include<bits/stdc++.h>
using namespace std;
#define ld long double

int main(){
    int n; cin>>n;
    ld tot=0;
    for(int i=0;i<n;++i){
        int t; cin>>t; tot+=t;
    }
    cout<<fixed<<setprecision(10)<<tot/n<<endl;
}
