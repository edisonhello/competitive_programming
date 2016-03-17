#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define imnot guagua
using namespace std;

inline int rit(){
    int t=0;
    char j;
    do{j=getchar();}while((j<'0' || j>'9'));
    do{
        t = t*10+j-'0';
        j=getchar();

    }while((j>='0' && j<='9'));
    return t;
}

int main(){
    float b=-0.6;
    cout<<(int)b;
}
