#include<bits/stdc++.h>
using namespace std;

double frand(){
    return double(rand())/RAND_MAX*100;
}

int main(){
    srand(time(0)+clock());
    int t=1; while(t--){
        int n=300; 
        cout<<n<<endl;
        for(int i=0;i<n;++i){
            cout<<frand()<<" "<<frand()<<" "<<frand()<<endl;
        }
    }
}
