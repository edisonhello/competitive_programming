#include<bits/stdc++.h>
using namespace std;

int mrand(int l,int r){
    return floor((double)rand()/RAND_MAX*(r-l+1)+l);
}
vector<int> a;
int main(){
    srand(time(0));
    int N=mrand(990000,1000000); cout<<N<<endl;
    while(a.size()<N){
        while(a.size()<N)a.push_back(mrand(1,1000000000));
        sort(a.begin(),a.end());
        a.resize();
    }
    for(int i=0;i<N;++i)cout<<mrand(1,1000000000)<<" "<<mrand(1,1000000000)<<endl;
}
