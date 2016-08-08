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

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    int n=rit();

    int mx=-989;
    int cnt=0;
    int fnt=999999;
    for(int i=0;i<n;i++){
        int t=rit();
        if(t>fnt){
            cnt++;
        }
        else{
            cnt=1;
        }
        mx=max(mx,cnt);

        fnt=t;
    }
    cout<<mx<<endl;
}
