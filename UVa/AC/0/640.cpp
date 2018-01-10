#include<bits/stdc++.h>
using namespace std;

int gene(int x){
    int gen=0;
    while(x){
        gen+=x%10;
        x/=10;
    } return gen;
}

bitset<1000099> gened;
int main(){
    int N;
    if(cin>>N); else N=1000000;
    for(int i=1;i<=N;++i){
        gened[i+gene(i)]=1;
        if(!gened[i])cout<<i<<'\n';
    }
}
