#include<bits/stdc++.h>
using namespace std;

void pit(int x){
    printf("%d ",x);
}

int main(){
    long long n,x,m; while(scanf("%lld%lld%lld",&x,&n,&m)==3){
        pit(x); --m;
        while(m--){
            x=x*x%n;
            pit(x); 
        }
        puts("");
    }
}
