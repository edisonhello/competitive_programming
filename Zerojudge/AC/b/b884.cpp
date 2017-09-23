#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--){
        double x,y;cin>>x>>y;
        double yee=100-(x+y);
        if(0.0<yee&&yee<=30.0)cout<<"sad!"<<endl;
        else if(30.0<yee&&yee<=60.0)cout<<"hmm~~"<<endl;
        else if(60.0<yee&&yee<100.0)cout<<"Happyyummy"<<endl;
        else cout<<"evil!!"<<endl;
    }
}
