#include<cmath>
#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;while(n--){
        int a,b,c;cin>>a>>b>>c;
        if((int)sqrt(b*b-a*c*4)*(int)sqrt(b*b-a*c*4)==b*b-a*c*4)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
}
