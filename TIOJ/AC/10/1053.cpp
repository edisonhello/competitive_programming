#include<iostream>

using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a,b;cin>>a>>b;
    cout<<((max(a,b)%min(a,b))?"N\n":"Y\n");
}
