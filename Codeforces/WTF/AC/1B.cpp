#include<iostream>
#include<set>
#include<bitset>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    int t;
    bitset<10005> b;
    while(n--){
        cin>>t;
        t%=m;
        b=b|(b<<t)|(b>>(m-t));
        b[t]=1;
        if(b[0]){cout<<"YES\n";return 0;}
    }
    cout<<"NO\n";
}
