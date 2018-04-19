#include<bits/stdc++.h>
using namespace std;

long long x[500005],y[500005],z[500005];

double rnd(){
    return (long long)rand()*rand()*rand()*rand()*rand()%((1ll<<32)+1);
}

int main(){
    srand(time(0));
    int n=500000;
    for(int i=1;i<=n;++i){
        while(x[i]==0 && y[i]==0 && z[i]==0){
            x[i]=rnd(); y[i]=rnd(); z[i]=rnd();
        }
    }

    cout<<n<<endl;
    for(int i=1;i<=n;++i)cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<endl;
}
