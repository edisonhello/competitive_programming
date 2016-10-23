#include<bits/stdc++.h>
#define ld long double
using namespace std;
int n;
ld r,g,b,av;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n*n;++i){
        cin>>r>>g>>b;
        cout<<fixed<<setprecision(4)
            <<0.5149*r+0.3244*g+0.1607*b<<" "
            <<0.2654*r+0.6704*g+0.0642*b<<" "
            <<0.0248*r+0.1248*g+0.8504*b<<'\n';
        av+=0.2654*r+0.6704*g+0.0642*b;
    }
    cout<<"The average of Y is "<<fixed<<setprecision(4)<<av/n/n<<'\n';
}
