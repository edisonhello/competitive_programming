#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    cout<<min({a*n,n/m*b+n%m*a,(n/m+1)*b})<<endl;
}
