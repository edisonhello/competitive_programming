#include<bits/stdc++.h>
using namespace std;

bool ok[111];
int main(){
    ok[0]=1; for(int i=3;i<=100;i+=3)ok[i]=1;
    for(int i=7;i<=100;++i)if(ok[i-7])ok[i]=1;
    int n; cin>>n; while(cin>>n){
        cout<<(ok[n]?"YES":"NO")<<endl;
    }
}
