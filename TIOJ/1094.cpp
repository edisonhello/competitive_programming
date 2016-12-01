#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;

struct node{
    node *ch[2];
    int cnt;
}

int main(){
    int n,x[35];
    bitset<20> b[35];
    while(cin>>n,n){
        for(int i=0;i<n;++i)cin>>x[i];
        sort(x,x+n);
        for(int i=0;i<n;++i){
            b[i]=x[i];
        }
    }
}
