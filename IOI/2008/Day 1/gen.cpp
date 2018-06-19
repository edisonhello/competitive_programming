#include<bits/stdc++.h>
using namespace std;

int mr(int l,int r){
    return (double)(rand())/RAND_MAX*(r-l+1)+l;
}

int main(){
    srand(clock());
    int n=10;
    cout<<n<<endl;
    for(int i=1;i<=n;++i){
        int u=i;
        while(u==i){
            u=mr(1,n);
        }
        cout<<u<<" "<<mr(1,15)<<endl;
    }
}
