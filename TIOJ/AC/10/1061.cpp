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

int f[5][5],all,ow,xw,dw;
set<ll> rec;

void P(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(f[i][j]==0)cout<<'-';
            if(f[i][j]==1)cout<<'O';
            if(f[i][j]==-1)cout<<'X';
        }
        cout<<endl;
    }
}

void REC(char c){
    // cout<<"REC "<<(int)c<<endl;
    ll hash=0,base=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            hash+=((ll)f[i][j]+1ll)*base;
            base*=3;
        }
    }
    if(rec.find(hash)!=rec.end())return;
    rec.insert(hash);
    all++;
    if(c== 1)ow++;
    if(c==-1)xw++;
    if(c== 0)dw++;
}

bool STOP(){
    // P();
    if(f[0][0]==1&&f[0][1]==1&&f[0][2]==1){REC(1); return 1;}
    if(f[1][0]==1&&f[1][1]==1&&f[1][2]==1){REC(1); return 1;}
    if(f[2][0]==1&&f[2][1]==1&&f[2][2]==1){REC(1); return 1;}
    if(f[0][0]==1&&f[1][0]==1&&f[2][0]==1){REC(1); return 1;}
    if(f[0][1]==1&&f[1][1]==1&&f[2][1]==1){REC(1); return 1;}
    if(f[0][2]==1&&f[1][2]==1&&f[2][2]==1){REC(1); return 1;}
    if(f[0][0]==1&&f[1][1]==1&&f[2][2]==1){REC(1); return 1;}
    if(f[0][2]==1&&f[1][1]==1&&f[2][0]==1){REC(1); return 1;}

    if(f[0][0]==-1&&f[0][1]==-1&&f[0][2]==-1){REC(-1); return 1;}
    if(f[1][0]==-1&&f[1][1]==-1&&f[1][2]==-1){REC(-1); return 1;}
    if(f[2][0]==-1&&f[2][1]==-1&&f[2][2]==-1){REC(-1); return 1;}
    if(f[0][0]==-1&&f[1][0]==-1&&f[2][0]==-1){REC(-1); return 1;}
    if(f[0][1]==-1&&f[1][1]==-1&&f[2][1]==-1){REC(-1); return 1;}
    if(f[0][2]==-1&&f[1][2]==-1&&f[2][2]==-1){REC(-1); return 1;}
    if(f[0][0]==-1&&f[1][1]==-1&&f[2][2]==-1){REC(-1); return 1;}
    if(f[0][2]==-1&&f[1][1]==-1&&f[2][0]==-1){REC(-1); return 1;}
    // cout<<"NO LINE"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(f[i][j]==0){
                // cout<<f[i][j]<<" : not full @ "<<i<<" "<<j<<endl;
                goto notFull;
            }
        }
    }
    // cout<<"FULL!"<<endl;
    REC(0);
    return 1;
    notFull:;
    return 0;
}

void _p(int put){
    if(STOP()){
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!f[i][j]){
                f[i][j]=put;
                // cout<<"put "<<i<<" "<<j<<" "<<put<<endl;
                _p(-put);
                f[i][j]=0;
            }
        }
    }
}

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    int os=0,xs=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(s[i*3+j]=='O'){
                f[i][j]=1;
                os++;
            }
            else if(s[i*3+j]=='X'){
                f[i][j]=-1;
                xs++;
            }
        }
    }
    if(os==xs){
        _p(1);
    }
    else{
        _p(-1);
    }
    cout<<all<<" "<<ow<<" "<<xw<<" "<<dw<<endl;
}
