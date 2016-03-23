#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define imnot guagua
using namespace std;

inline ull rit(){
    ull t=0,key=1;
    char j;
    do{
        j=getchar();
        if(j=='-')key=-1;
    }while((j<'0' || j>'9'));
    do{
        t = t*10+j-'0';
        j=getchar();

    }while((j>='0' && j<='9'));
    return t*key;
}

int main(){
    int n=rit();
    cout<<n<<endl;
}
