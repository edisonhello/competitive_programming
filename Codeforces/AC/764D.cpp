#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;cout<<"YES\n";
    while(n--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        cout<<2*(a&1)+(b&1)+1<<endl;
    }
}
