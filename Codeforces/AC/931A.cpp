#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b; cin>>a>>b;
    int d=abs(a-b);
    int dd=d/2;
    cout<<(1+dd)*dd+(d&1?dd+1:0)<<endl;
}
