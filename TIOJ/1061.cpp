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

int f[5][5];
int all,ow,xw,de;
set<ll> rec;

void pnt(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<(f[i][j]==1?'O':(f[i][j]==-1?'X':'-'));
        }
        cout<<"\n";
    }
    // cout<<'\n';
}

bool chk(int c){
    for(int i=0;i<3;i++){
        if(f[i][0]==c&&f[i][1]==c&&f[i][2]==c){
            return 1;
        }
        if(f[0][i]==c&&f[1][i]==c&&f[2][i]==c){
            return 1;
        }
    }
    if(f[0][0]==c&&f[1][1]==c&&f[2][2]==c){
        return 1;
    }
    else if(f[0][2]==c&&f[1][1]==c&&f[2][0]==c){
        return 1;
    }
    return 0;
}

bool full(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!f[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

bool rep(){
    ll has=0,bas=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            has+=bas*((ll)(f[i][j]+1));
            bas*=3;
        }
    }
    if(rec.count(has)){
        return 1;
    }
    else{
        rec.insert(has);
        return 0;
    }
}

ll getH(){
    ll has=0,bas=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            has+=bas*((ll)(f[i][j]+1));
            bas*=3;
        }
    }
    return has;
}

bool chkED(){
    if(rep()){
        return 1;
    }
    if(chk(1)){
        all++;
        ow++;
    }
    else if(chk(-1)){
        all++;
        xw++;
    }
    else if(full()){
        all++;
        de++;
    }
}

void dfs(int pt){
    // cout<<"dfs:"<<x<<y<<" "<<pt<<endl;
    // pnt();
    // int chkk=;
    if(chkED()){
        // cout<<x<<y<<"got ED"<<endl;
        // cout<<getH()<<endl;
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!f[i][j]){
                f[i][j]=pt;
                // cout<<"put"<<i<<j<<" "<<pt<<endl;
                dfs(-pt);
                // cout<<"jiz\n";
                f[i][j]=0;
            }
        }
    }
}

int main(){
    string s;cin>>s;
    int ocnt=0,xcnt=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(s[i*3+j]=='O'){
                f[i][j]=1;
                ocnt++;
            }
            else if(s[i*3+j]=='X'){
                f[i][j]=-1;
                xcnt++;
            }
        }
    }
    dfs((ocnt==xcnt?1:-1));
    cout<<all<<" "<<ow<<" "<<xw<<" "<<de<<endl;
}
