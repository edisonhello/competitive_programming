#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c;
int main(){
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        if(a==1)cout<<b+c<<endl;
        if(a==2)cout<<b-c<<endl;
        if(a==3)cout<<b*c<<endl;
        if(a==4)cout<<b/c<<endl;
    }
}
