#include<iostream>
using namespace std;
int main(){
    long long n;cin>>n;
    if(n*(n+1)>1000000000 || n==1)cout<<"-1"<<endl;
    else cout<<n<<" "<<n+1<<" "<<n*(n+1)<<endl;
}
