#include<bits/stdc++.h>
using namespace std;

int rand(int l,int r){
    int val=rand()*rand()*rand(); val=abs(val);
    val%=r-l+1;
    return val+l;
}

int main(){
    srand(clock());
    int n=100000-rand(0,100);
    cout<<n<<endl;
    for(int i=1;i<=n;++i)cout<<rand(1,1000000)<<" "; cout<<endl;
    for(int i=1;i<=n;++i){
        int l=rand(1,n-1),r=rand(l+1,n);
        cout<<l<<" "<<r<<endl;
    }
}
