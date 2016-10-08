#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int rit_t,rit_k;
char rit_c;
inline int rit();

int nxt[35],ptr,n,cnt;
vector<int> ans;

void dfs(int step){
    // cout<<step<<endl;
    if(step>n){
        cnt++;
        int now=0;
        if(ans.size()==0){
            while(now!=-1){
                ans.PB(now);
                now=nxt[now];
            }
        }
        else{
            int pnt=0;
            bool win=0;
            while(now!=-1){
                if(ans[pnt]<now || win){
                    win=1;
                    ans[pnt]=now;
                    now=nxt[now];
                    pnt++;
                    continue;
                }
                if(ans[pnt]>now){
                    break;
                }
                if(ans[pnt]==now){
                    pnt++;
                    now=nxt[now];
                    continue;
                }
            }
        }
        return;
    }
    int now=0;
    while(nxt[now]!=-1){
        int nx=nxt[now];
        if(step%(now+nx)==0){
            nxt[step]=nx;
            nxt[now]=step;
            dfs(step+1);
            nxt[now]=nx;
        }
        now=nxt[now];
    }
}

int main(){
    n=rit();
    nxt[0]=2;
    nxt[2]=3;
    nxt[3]=1;
    nxt[1]=-1;
    if(n==1){
        cout<<"1\n0 1\n";
        return 0;
    }
    if(n==2){
        cout<<"1\n0 2 1\n";
        return 0;
    }
    if(n==3){
        cout<<"1\n0 2 3 1\n";
        return 0;
    }
    dfs(4);
    cout<<cnt<<'\n';
    for(int i=0;i<n+1;i++){
        if(i)cout<<" ";
        cout<<ans[i];
    }
    cout<<'\n';
}

inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar_unlocked();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar_unlocked();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
