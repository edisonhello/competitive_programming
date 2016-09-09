#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

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
};

struct pnt{
    int x,y,len;
    pnt():x(0),y(0),len(0){};
    pnt(int xx,int yy,int lll):x(xx),y(yy),len(lll){};
};

string mp[10]={
    "*****************",
    "*...*.......**..*",
    "**..*....*.*.*..*",
    "*......*.**.**.**",
    "*..**...**..**.**",
    "**.....**..*.*..*",
    "*....*..........*",
    "*.....****.*...**",
    "****.*.*........*",
    "*****************"
};
int n,m,t,ans;
int fx,fy,sx,sy,ex,ey;
bool gone[20][20],fgone[20][20];

queue<pnt> fq,mq;

void fWalk(){
    int time = fq.front().len;
    while(fq.size() && fq.front().len==time){
        pnt tmp = fq.front();fq.pop();
        int x = tmp.x,y = tmp.y,len = tmp.len;
        if(!fgone[x+1][y] && mp[x+1][y]!='!' && x+1 <n){fgone[x+1][y]=1;mp[x+1][y]='*';fq.push({x+1,y,len+1});};
        if(!fgone[x-1][y] && mp[x-1][y]!='!' && x-1>=0){fgone[x-1][y]=1;mp[x-1][y]='*';fq.push({x-1,y,len+1});};
        if(!fgone[x][y+1] && mp[x][y+1]!='!' && y+1 <m){fgone[x][y+1]=1;mp[x][y+1]='*';fq.push({x,y+1,len+1});};
        if(!fgone[x][y-1] && mp[x][y-1]!='!' && y-1>=0){fgone[x][y-1]=1;mp[x][y-1]='*';fq.push({x,y-1,len+1});};
    }
}

int meGo(){
    int time = mq.front().len;
    while(mq.size() && mq.front().len==time){
        pnt tmp = mq.front();mq.pop();
        int x = tmp.x,y = tmp.y,len = tmp.len;
        if(mp[x][y]=='!')return len;
        if(!gone[x+1][y] && mp[x+1][y]!='*'){gone[x+1][y]=1;mq.push({x+1,y,len+1});};
        if(!gone[x-1][y] && mp[x-1][y]!='*'){gone[x-1][y]=1;mq.push({x-1,y,len+1});};
        if(!gone[x][y+1] && mp[x][y+1]!='*'){gone[x][y+1]=1;mq.push({x,y+1,len+1});};
        if(!gone[x][y-1] && mp[x][y-1]!='*'){gone[x][y-1]=1;mq.push({x,y-1,len+1});};
    }
    return -1;
}

void P(){
    cout<<"now map:\n";
    for(int i=0;i<n;i++){
        cout<<mp[i]<<endl;
    }
    cout<<endl;
}

void S(){
    fq.push({fx,fy,0});
    mp[fx][fy]='*';
    fgone[fx][fy]=1;
    P();
    for(int time=1;time<t;time++){
        fWalk();
        P();
    }
    cout<<"pre gone.\n\n";
    mq.push({sx,sy,0});
    gone[sx][sy]=1;
    int cnt=1200;
    while(cnt--){
        ans++;
        fWalk();
        int res = meGo();
        if(res!=-1){
            cout<<res<<endl;
            return;
        }
        P();
    }
    cout<<"Help!\n";
}

int main(){
    n=10,m=17;
    fx=rit(),fy=rit(),t=rit(),sx=rit(),sy=rit(),ex=rit(),ey=rit();

    mp[ex][ey]='!';

    S();
}
