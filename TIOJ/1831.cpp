#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl

int n,m,k,i,j,x,y;
bool a[102][102],o;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    for(i=0;i<m;i++){
        cin>>x>>s>>y;
        if(s=="->"){
            a[x][y]=1;
        }
        if(s=="<-"){
            a[y][x]=1;
        }
    }
    if(k==0){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        for(i=1;i<=n;i++){
            o=0;
            cout<<i<<" ->";
            for(j=1;j<=n;j++){
                if(a[i][j]){
                    cout<<" "<<j;
                    o++;
                }
            }
            if(!o)cout<<" 0";
            cout<<endl;
        }
    }
}
