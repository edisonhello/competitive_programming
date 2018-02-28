#include<bits/stdc++.h>
using namespace std;

int mrand(int l,int r){
    return rand()*(r-l)+l;
}
int main(){
    freopen("in","w",stdout);
    srand(time(0));
    const int N=100; cout<<N<<endl;
    for(int i=0;i<N;++i)cout<<mrand(1,25555)<<" "<<mrand(1,25555)<<endl;
}
