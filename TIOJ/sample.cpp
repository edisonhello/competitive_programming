#include<bits/stdc++.h>
using namespace std;

struct Foo{
    static int var;
    int func(int n=var,int m=var+5){
        return n*m;
    }
    int init(int n){
        var=n;
    }
} meow;

int main(){
    meow.init(7122);
    int n; cin>>n;
    cout<<meow.func()<<endl;
}
