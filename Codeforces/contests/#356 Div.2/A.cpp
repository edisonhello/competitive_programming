#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
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
int main(){
    vint a;
    int sum=0;
    for(int i=0;i<5;i++){
        int t=rit();
        sum+=t;
        a.PB(t);
    }
    sort(a.begin(),a.end());
    int x3=0;
    if(a[0]==a[2])x3=a[1];
    if(a[1]==a[3])x3=a[2];
    if(a[2]==a[4])x3=a[3];

    int x2=0;
    if(a[0]==a[1])x2=a[1];
    if(a[1]==a[2])x2=a[2];
    if(a[2]==a[3])x2=a[3];
    if(a[3]==a[4])x2=a[4];

    if(x2*2>x3*3){
        sum-=x2*2;
        cout<<sum<<endl;
        return 0;
    }
    else if(x2*2==x3*3){
        sum-=x2*2;
        cout<<sum<<endl;
        return 0;
    }
    else if(x2*2<x3*3){
        sum-=x3*3;
        cout<<sum<<endl;
        return 0;
    }
    cout<<sum<<endl;
}
