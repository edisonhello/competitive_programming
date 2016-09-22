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
#define DE cout<<"de"<<endl;

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

int m,n;
// string s[1005];
vector<string> s;
bool gone[1005][1005];

void g(int i,int j){
    gone[i][j]=1;
    if(i!=m-1 && !gone[i+1][j] && s[i][j]==s[i+1][j])g(i+1,j);
    if(i!=0   && !gone[i-1][j] && s[i][j]==s[i-1][j])g(i-1,j);
    if(j!=n-1 && !gone[i][j+1] && s[i][j]==s[i][j+1])g(i,j+1);
    if(j!=0   && !gone[i][j-1] && s[i][j]==s[i][j-1])g(i,j-1);
    if(i!=m-1 && j!=n-1 && !gone[i+1][j+1] && s[i][j]==s[i+1][j+1])g(i+1,j+1);
    if(i!=m-1 && j!=0   && !gone[i+1][j-1] && s[i][j]==s[i+1][j-1])g(i+1,j-1);
    if(i!=0   && j!=n-1 && !gone[i-1][j+1] && s[i][j]==s[i-1][j+1])g(i-1,j+1);
    if(i!=0   && j!=0   && !gone[i-1][j-1] && s[i][j]==s[i-1][j-1])g(i-1,j-1);
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while(cin>>m>>n&&m&&n){
        // memset(s,0,sizeof(s));
        s.resize(m);
        for(int i=0;i<m;i++){
            cin>>s[i];
        }
        memset(gone,0,sizeof(gone));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!gone[i][j] && s[i][j]=='1'){
                    cnt++;
                    g(i,j);
                    // DE;
                }
            }
        }
        cout<<cnt<<endl;
    }
}
