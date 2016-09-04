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
    while(cin>>m>>n&&m&&n){
        ll mm=min(m,n);
        ll nn=max(m,n);
        ll ans=mm*mm*nn-(nn+mm)*((mm*(mm-1))/2)+((mm-1)*mm*(2*mm-1))/6;
        cout<<ans<<endl;
    }
}
