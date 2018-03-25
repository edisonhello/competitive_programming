#include<bits/stdc++.h>
using namespace std;

int main(){
    int x; cin>>x;
    int c=0;
    for(int i=0;i<31;++i){
        if(x&(1<<i))++c;
    }
    cout<<c<<endl;
}
