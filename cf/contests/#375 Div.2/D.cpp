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

int rit_t,rit_k;
char rit_c;
inline int rit();

struct SZ{int sz,x,y;};
bool operator<(const SZ &a,const SZ &b){
    return a.sz<b.sz;
}
int n,m,k;
string s[55];
pii djs[55][55];
int sz[55][55];
bool isW[55][55];
int nk;
int dx[4],dy[4];
vector<SZ> szs;
int cnted[55*55+55];
int shf[55*55+55];
int ched;
bool isO[55][55];
pii F(pii a){
    if(djs[a.X][a.Y]==a)return a;
    else return djs[a.X][a.Y]=F(djs[a.X][a.Y]);
}
void U(pii a,pii b){
    a=F(a);
    b=F(b);
    if(a==b)return;
    if(sz[b.X][b.Y]>sz[a.X][a.Y])swap(a,b);
    djs[b.X][b.Y]=a;
    sz[a.X][a.Y]+=sz[b.X][b.Y];
    return;
}
bool C(pii a,pii b){
    return F(a)==F(b);
}
int main(){
    cin>>n>>m>>k;
    k++;
    for(int i=0;i<=m+1;i++){
        s[0]+='.';
        s[n+1]+='.';
    }
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]='.'+s[i]+'.';
    }
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            if(s[i][j]=='.'){
                isW[i][j]++;
            }
        }
    }
    for(int i=0;i<53;i++){
        for(int j=0;j<53;j++){
            djs[i][j]={i,j};
            if(isW[i][j]){
                sz[i][j]=1;
            }
        }
    }
    // cout<<"djs:\n";
    // for(int i=0;i<=n+1;i++){
    //     for(int j=0;j<=m+1;j++){
    //         cout<<djs[i][j].X*53+djs[i][j].Y<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            if(!isW[i][j])continue;
            for(int dir=0;dir<4;dir++){
                if(dir==2 && j==0)continue;
                if(dir==3 && i==0)continue;
                if(isW[i+dx[dir]][j+dy[dir]]){
                    // cout<<i<<" "<<j<<" is water and "<<i+dx[dir]<<" "<<j+dy[dir]<<endl;
                    U({i,j},{i+dx[dir],j+dy[dir]});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(C({0,0},{i,j})){
                isW[i][j]=0;
                isO[i][j]=1;
            }
        }
    }
    // cout<<"djs:\n";
    // for(int i=0;i<=n+1;i++){
    //     for(int j=0;j<=m+1;j++){
    //         cout<<djs[i][j].X*53+djs[i][j].Y<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            if(!isW[i][j])continue;
            pii par=F({i,j});
            if(!cnted[par.X*53+par.Y]){
                szs.push_back({sz[par.X][par.Y],par.X,par.Y});
                cnted[par.X*53+par.Y]=1;
            }
        }
    }
    sort(szs.begin(),szs.end());
    // cout<<"szs size:"<<szs.size()<<endl;
    for(int i=0;i<(int)(szs.size()-k);i++){
        SZ &now=szs[i];
        shf[now.x*53+now.y]=1;
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            pii fres=F({i,j});
            if(shf[fres.X*53+fres.Y]==1){
                s[i][j]='*';
                ched++;
            }
        }
    }
    cout<<ched<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(isO[i][j]){
                cout<<'.';
            }
            else{
                cout<<s[i][j];
            }
        }
        cout<<endl;
    }
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
