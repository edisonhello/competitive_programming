#include<bits/stdc++.h>
using namespace std;

inline int rd(int n){
    return (((rand()<<16)+rand())%n+n)%n;
}

const int N = 100000;

int main(){
    srand(time(NULL));
    int n=rd(N)+1+700000; cout<<n<<endl;
    for(int i=0;i<n;++i){
        int s=rd(n);
        int t=rd(n-s)+s;
        cout<<s<<" "<<t<<endl;
    }
}
// 524288
