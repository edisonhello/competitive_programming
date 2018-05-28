#include<bits/stdc++.h>
using namespace std;


int main(){
    srand(clock());
    int n=10000,q=10000;
    cout<<n<<" "<<q<<endl;
    for(int i=1;i<=q;++i){
        cout<<1<<" "<<n<<" "<<rand()%n+1<<endl;
    }
}
