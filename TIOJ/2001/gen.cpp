#include<bits/stdc++.h>
using namespace std;

#define N 200000
#define K 200000
#define T 100000

long long t[200008];

int mrand(int l,int r){
    return floor((double)rand()/RAND_MAX*(r-l+1)+l);
}

int main(){
    srand(time(0));
    int n=N,k=K;
    for(int i=1;i<=n;++i){
        t[i]=mrand(1,T);
        // t[i]=(abs(rand()*rand())%100000+1,(n-i<300?1:100000));
    }

    cout<<n<<" "<<k<<endl;
    for(int i=1;i<=n;++i)cout<<t[i]<<" \n"[i==n];
}
