#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x+5)
#define X first
#define Y second
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
}
int n;
vint a,a1,a2,ab;

int main(){
    n=rit();
    a.rz(n);
    a1.rz(n);
    a2.rz(n);
    ab.rz(n);
    for(int i=1;i<=n;i++)a[i]=rit();

    for(int i=1;i<=n;i++){
        if(a[i]==1||a[i]==3){
            a1[i]=min(a2[i-1],ab[i-1]);
        }
        else a1[i]=98989;
        if(a[i]==2||a[i]==3){
            a2[i]=min(a1[i-1],ab[i-1]);
        }
        else a2[i]=98989;
        ab[i]=min(a1[i-1],min(a2[i-1],ab[i-1]))+1;
    }
    cout<<min(min(a1[n],a2[n]),ab[n]);
}
