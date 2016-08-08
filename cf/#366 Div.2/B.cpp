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

int n;
int v[100005];

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    n=rit();
    int cnt=0;
    for(int i=0;i<n;i++){
        v[i]=rit();
        cnt += (v[i]-1);
        if(cnt&1){
            cout<<1<<'\n';
        }
        else{
            cout<<2<<'\n';
        }
    }

}
