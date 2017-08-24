#include<bits/stdc++.h>

using namespace std;


int dig[10];


inline int sep(int i){
    int cnt=0;
    while(i!=0){
        cnt+=dig[i%10];
        i/=10;
    }
    return cnt;
}

int main(){
    dig[0] = 6;
    dig[1] = 2;
    dig[2] = 5;
    dig[3] = 5;
    dig[4] = 4;
    dig[5] = 5;
    dig[6] = 6;
    dig[7] = 3;
    dig[8] = 7;
    dig[9] = 6;

    int cnt=0;
    int a,b;cin>>a>>b;

    for(int i=a;i<=b;i++){
        cnt += sep(i);
    }

    cout<<cnt<<endl;
}
