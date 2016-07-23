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

vector<bool> putx,puty;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;
    putx.rz(n+5);
    puty.rz(n+5);
    ull xleft=(ull)n;
    ull yleft=(ull)n;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(!putx[x]){
            xleft--;
            putx[x]=1;
            // printf("a");
        }
        if(!puty[y]){
            yleft--;
            puty[y]=1;
            // printf("b");
        }
        if(i)cout<<" ";
        cout<<xleft*yleft;
    }
    cout<<'\n';


}
