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
// inline int rit(){
//     int t=0,k=1;
//     char c;
//     do{
//         c=getchar();
//         if(c=='-')k=-1;
//     }while(c<'0'||c>'9');
//     do{
//         t=t*10+c-'0';
//         c=getchar();
//     }while(c>='0'&&c<='9');
//     return t*k;
// }
struct p{
    int c,e;
};
bool operator< (const p &a,const p &b){
    return a.e>b.e;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    while(cin>>n && n){
        vector<p> a;
        a.rz(n);
        for(int i=0;i<n;i++){
            cin>>a[i].c>>a[i].e;
        }
        sort(a.begin(),a.end());
        int mxt=-99,t=0;
        for(int i=0;i<n;i++){
            mxt = max(mxt,t+a[i].c+a[i].e);
            t += a[i].c;
        }
        cout<<mxt<<'\n';
    }
}
