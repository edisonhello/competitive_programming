#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,w; cin>>n>>k>>w;
    int lef=n;
    while(lef>=k){
        int nw=lef/k;
        lef%=k;
        n+=nw*w;
        lef+=nw*w;
    }
    cout<<n<<endl;
}
