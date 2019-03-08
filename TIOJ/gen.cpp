#include<bits/stdc++.h>
using namespace std;


int main(){
    srand(time(0)*clock()+clock());
    int n=rand()%1000+1, t=rand()%1000000000+1;
    cout<<n<<" "<<t<<endl;
    for(int i=0;i<n;++i){
        int a=rand()%500000+1,b=rand()%500000+1;
        cout<<a+b<<" "<<a<<endl;
    }
}
