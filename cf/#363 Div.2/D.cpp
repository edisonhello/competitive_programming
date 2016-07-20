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
vint a;
vector<vector<int> > b;
vector<bool> gone;
int n;
int rootID;
int chg;

void dfs(int now){
    if(!gone[a[now]]){
        gone[now]=1;
        dfs(a[now]);
    }
    for(int i=0;i<(int)b[now].size();i++){
        if(!gone[b[now][i]]){
            gone[b[now][i]]=1;
            dfs(b[now][i]);
        }
    }
}

int main(){
    n=rit();
    a.rz(n+5);
    b.rz(n+5);
    gone.rz(n+5);
    for(int i=1;i<=n;i++){
        a[i]=rit();
        if(a[i]==i){
            if(rootID){
                a[i]=rootID;
                chg++;
            }
            else{
                rootID=a[i];
            }
        }
        b[a[i]].PB(i);
    }

    if(!rootID){
        a[1]=1;
        chg++;
        a.clear();
        b.clear();
        a.rz(n+5);
        b.rz(n+5);
        for(int i=1;i<=n;i++){
            if(a[i]==i){
                if(rootID){
                    a[i]=rootID;
                    chg++;
                }
                else{
                    rootID=a[i];
                }
            }
            b[a[i]].PB(i);
        }
    }

    gone[rootID]=1;
    dfs(rootID);

    for(int i=1;i<=n;i++){
        if(!gone[i]){
            a[i]=rootID;
            chg++;
            /*a.clear();
            b.clear();
            a.rz(n+5);
            b.rz(n+5);
            for(int i=1;i<=n;i++){
                if(a[i]==i){
                    if(rootID){
                        a[i]=rootID;
                        chg++;
                    }
                    else{
                        rootID=a[i];
                    }
                }
                b[a[i]].PB(i);
            }*/
            dfs(i);
        }
    }

    printf("%d\n",chg);
    for(int i=1;i<=n;i++){
        if(i-1)printf(" ");
        printf("%d",a[i]);
    }
    putchar('\n');
}
