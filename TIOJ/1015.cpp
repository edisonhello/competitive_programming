#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x+5)
#define X first
#define Y second
#define M (l+r)/2

ll n,mxw;
vint a;
ll mx;

/*inline ll rit(){
    ll t=0,k=1;
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
}*/

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll m,n;
    while(cin>>m>>n&&m){
        ll ans=0;
        for(int i=1;i<=min(m,n);i++){
            ans += (m-i+1)*(n-i+1);
        }
        cout<<ans<<'\n';
    }
}
