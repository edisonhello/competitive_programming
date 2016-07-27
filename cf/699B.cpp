#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x+5)
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
int n,m;

int mp[1005][1005];
vint x,y;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>n>>m;
    x.rz(n);
    y.rz(n);

    int cnt=0;
    for(int i=1;i<=n;i++){
        string t;
        for(int j=1;j<=m;j++){
            if(t[j-1]=='*'){
                mp[i][j]=1;
                x[i]++;
                y[j]++;
                cnt++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i]+y[j]-mp[i][j]==cnt){
                cout<<"YES\n"<<i<<" "<<j<<"\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
}
