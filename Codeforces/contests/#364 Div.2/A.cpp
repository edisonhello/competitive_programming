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
struct t{
    int cnt;
    int pnt;
};
bool operator<(const t &a,const t &b){
    return a.pnt<b.pnt;
}
int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    int n=rit();
    vector<t> a;
    a.rz(n);
    int sum=0;
    for(int i=0;i<n;i++){
        a[i].pnt=rit();
        a[i].cnt=i+1;
        sum+=a[i].pnt;
    }
    int foreach = sum/(n/2);
    sort(a.begin(),a.end());

    for(int i=0;i<n/2;i++){
        printf("%d %d\n",a[i].cnt,a[n-1-i].cnt);
    }


}
