#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define imnot guagua
using namespace std;

inline int rit(){
    int t=0,key=1;
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
//double t=1.0f;

int main(){
    double base;ll time;
    cin>>base>>time;
    double up = 1.000000011;
    double ans= 1;

    while(time>=1){
        if(time%2==1){
            ans *= up;
        }
        up *= up;
        time/=2;
    }

    printf("%.8f\n",base*ans);
}
