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
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    while(cin>>n && n){
        vint r,b;
        r.rz(n);
        b.rz(n);
        for(int i=0;i<n;i++)cin>>r[i];
        for(int i=0;i<n;i++)cin>>b[i];
        sort(r.begin(),r.end());
        sort(b.begin(),b.end());
        ull ans=0;
        for(int i=0;i<n;i++)ans+=(r[i]*b[i]);
        cout<<ans<<'\n';
    }
}
