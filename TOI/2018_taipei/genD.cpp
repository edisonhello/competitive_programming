#include<bits/stdc++.h>
using namespace std;

int mrand(int l,int r){
    return (double)rand()/RAND_MAX*(r-l)+l;
}
int main(){
    freopen("in","w",stdout);
    srand(time(0));
    cout<<9999<<" "<<9999<<" "<<100<<endl;
    for(int i=0;i<100;++i){
        cout<<100<<" "<<100<<" "<<mrand(1,100)<<endl;
    }
}

