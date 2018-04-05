#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,m; cin>>h>>m;
    int H,D,C,N; cin>>H>>D>>C>>N;
    if(h>=20){
        cout<<((H-1)/N+1)*C*0.8<<endl;
    }
    else cout<<min(double(((H-1)/N+1)*C),double(((H+(1200-(h*60+m))*D-1)/N+1)*C*0.8))<<endl;
}
