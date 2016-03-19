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
long double by = 1.000000011;
//double t=1.0f;

int main(){
    long double n;ll m;
    cin>>n>>m;

    long double ans = 1;

/*int pow3(int a,int b)
{
    int ans = 1,base = a;
    while(b!=0)
    {
        if(b&1)
            ans *= base;
        base *= base;
        b>>=1;
    }
    return ans;
}  */

    while(m!=0){
        //n*=by;

        if(m%2==1){
            ans*=by;
        }by*=by;

        m/=2;
    }

    printf("%.8Le\n",n*by);
}
