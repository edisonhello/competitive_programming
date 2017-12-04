#include<bits/stdc++.h>
using namespace std;

int mrand(int l,int r){
    return floor((double)rand()/RAND_MAX*(r-l+1)+l);
}
int main(){
    srand(time(0));
    int N=mrand(1500000,1500000); cout<<N<<endl;
    for(int i=0;i<N;++i)cout<<mrand(0,2000000000)<<" "<<mrand(0,2000000000)<<endl;
}
