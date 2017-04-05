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
/*inline int rit(){
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
}*/
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;cin>>n;
    string m;cin>>m;
    vint p;
    p.rz(n);
    for(int i=0;i<n;i++)cin>>p[i];

    int mn=1e9+5;
    for(int i=0;i<n-1;i++){
        if(m[i]=='R'&&m[i+1]=='L'){
            mn = min(mn,p[i+1]-p[i]);
        }
    }

    if(mn!=1e9+5)cout<<mn/2<<endl;
    else cout<<-1<<endl;

}
