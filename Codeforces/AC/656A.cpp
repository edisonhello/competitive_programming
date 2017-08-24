#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a=1;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        a*=2;
        if(i==12)a-=100;
    }
    cout<<a<<endl;
}
