#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
};

int f[35];

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    f[1]=1;
    f[2]=2;
    for(int i=3;i<=31;i++){
        f[i]=f[i-1]+f[i-2];
    }

    int t=rit();
    int n=1;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=f[i];j++){
            putchar((n%3)+'0');
            n++;
        }
        putchar('\n');
    }
}

