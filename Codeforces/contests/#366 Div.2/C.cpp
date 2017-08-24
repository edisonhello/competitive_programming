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

int n,q,c,x,t,p;
int nowunread;
int appunread[300005];
int appreaded[300005];
int que[300005];

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    n=rit();q=rit();

    for(int i=0;i<q;i++){
        c=rit();
        if(c==1){
            x=rit();
            nowunread++;
            appunread[x]++;
            que[p]=x;
            p++;
        }
        else if(c==2){
            x=rit();
            nowunread -= appunread[x];
            appreaded[x] += appunread[x];
            appunread = 0;
        }
        else if(c==3){
            t=rit();
            int pointer = p-1;
            for(int i=0;i<t;i++,pointer--){
                que[pointer]
            }
        }
        cout<<nowunread<<'\n';
    }
}
