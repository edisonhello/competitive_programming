#include<bits/stdc++.h>
using namespace std;

int rand(int l,int r){
    int val=rand()*rand()*rand(); val=abs(val);
    val%=r-l+1;
    return val+l;
}

int main(){
    srand(clock());
    cout<<rand(0,1000000000)<<" "<<rand(0,1000000000)<<" "<<rand(0,1000000000)<<" "<<rand(0,1000000000)<<" "<<rand(1001,1000000000)<<endl;
}
