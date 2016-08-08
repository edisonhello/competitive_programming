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

struct com{
    int t,x;
};

int n,q,t,x,r;
bool rall[300005];
stack<com> rec;

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    n=rit();q=rit();

    for(int i=0;i<q;i++){
        t=rit();
        x=rit();
        com tmp;
        tmp.t=t;
        tmp.x=x;
        rec.push(tmp);
    }


    for(int i=0;i<q;i++){
        com pro = rec.top();
        rec.pop();
        if(pro.t==2){
            rall[pro]
        }
    }
}
