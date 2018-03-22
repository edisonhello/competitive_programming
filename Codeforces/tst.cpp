#include <x86intrin.h> 
using namespace std;
#include<iostream>

int main(){
    cout<<__rdtsc()<<endl;
    cout<<CLOCKS_PER_SEC<<endl;
}
