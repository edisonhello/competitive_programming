#include<bits/stdc++.h>
using namespace std;

#define N 199990,200000
#define K 1,1
#define T 100000
#define L 1000,5000

long long t[200008];

int mrand(int l,int r){
    return floor((double)rand()/RAND_MAX*(r-l+1)+l);
}

int main(){
    srand(time(0));
    int n=mrand(N),k=mrand(K);
    int limit=mrand(L);
    for(int i=1;i<=n;++i){
        t[i]=mrand(1,T);
        // t[i]=(n-i<limit?1:100000);
    }

    cout<<n<<" "<<k<<endl;
    for(int i=1;i<=n;++i)cout<<t[i]<<" \n"[i==n];
}
