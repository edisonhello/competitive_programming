#include<bits/stdc++.h>
using namespace std;

int mr(int l,int r){
    return floor((double)rand()/RAND_MAX*(r-l+1))+l;
}

int main(){
    srand(time(0));
    freopen("in.txt","w",stdout);
    int n=10,k=4,q=10;
    cout<<n<<" "<<k<<" "<<q<<endl;
    for(int i=1;i<=n;++i){
        int L=mr(1,6),R=mr(L,10);
        cout<<mr(1,11)<<" "<<mr(1,k)<<" "<<L<<" "<<R<<endl;
    }
    for(int i=1;i<=q;++i){
        cout<<mr(1,11)<<" "<<mr(1,11)<<endl;
    }
}
