#include<bits/stdc++.h>
using namespace std;

int mr(int l,int r){
    return floor((double)rand()/RAND_MAX*(r-l+1))+l;
}

int main(){
    srand(time(0));
    int n=10;
    cout<<n<<endl;
    for(int i=1;i<=n;++i){
        cout<<mr(-10000000,100000000)<<" "<<mr(-100000000,100000000)<<" ";
        if(mr(0,1)){
            cout<<mr(1,300)<<endl;
        }
        else{
            cout<<mr(100000,100000000)<<endl;
        }
    }
}
