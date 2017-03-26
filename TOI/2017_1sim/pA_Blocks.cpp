#include<bits/stdc++.h>
using namespace std;

string mp[555];
struct block{int x1,y1,x2,y2;} inf;
vector<block> b;
bool v[555][555];
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
int n,m;

bool vaild(int i,int j){
    if(i<0 || j<0)return 0;
    if(i>=n || j>=m)return 0;
    return 1;
}
void dfs(int x,int y,int bn){
    queue<pair<int,int>> q;
    #define X first
    #define Y second
    q.push({x,y}); v[x][y]=1;
    while(q.size()){
        x=q.front().X, y=q.front().Y; q.pop();
        v[x][y]=1;
        b[bn].x1=min(b[bn].x1,x);
        b[bn].y1=min(b[bn].y1,y);
        b[bn].x2=max(b[bn].x2,x);
        b[bn].y2=max(b[bn].y2,y);
        for(int i=0;i<8;++i){
            if(vaild(x+dx[i],y+dy[i]) && mp[x+dx[i]][y+dy[i]]=='1' && !v[x+dx[i]][y+dy[i]]){
                q.push({x+dx[i],y+dy[i]});
                v[x+dx[i]][y+dy[i]]=1;
            }
        }
    }
    #undef X
    #undef Y
}


bool cover(block &bi,block &bj){
    bool xcover=(bi.x1<=bj.x2&&bi.x2>=bj.x1);
    bool ycover=(bi.y1<=bj.y2&&bi.y2>=bj.y1);
    return xcover&&ycover;
}

block ary[990000];
int fnt[990000],bak[990000];
int fst,lst;

void pb(block &bk){
//    cout<<"pb! give "<<lst+1<<endl;
    ary[++lst]=bk;
    fnt[lst]=lst-1;
    bak[lst-1]=lst;
    if(fst==0)fst=lst;
}
void es(int i){
    if(fst==lst){
        fst=lst=0;
    }
    if(i==fst){
        fst=bak[fst];
        fnt[fst]=0;
    }
    else if(i==lst){
        lst=fnt[lst];
        bak[lst]=0;
    }
    else{
        bak[fnt[i]]=bak[i];
        fnt[bak[i]]=fnt[i];
    }
}
int cnt=0;
vector<block> big;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    inf.x1=555,inf.y1=555,inf.x2=-1,inf.y2=-1;
    int bks=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]=='1' && !v[i][j]){
                b.push_back(inf);
                dfs(i,j,bks++);
            }
        }
    }

    for(int i=0;i<bks;++i){
        pb(b[i]);
        tryAgain:
        for(int j=fst;j!=lst;j=bak[j]){
            ++cnt;
            if(cover(ary[lst],ary[j])){
                block tmp=inf;
                tmp.x1=min(ary[lst].x1,ary[j].x1);
                tmp.y1=min(ary[lst].y1,ary[j].y1);
                tmp.x2=max(ary[lst].x2,ary[j].x2);
                tmp.y2=max(ary[lst].y2,ary[j].y2);
                es(lst), es(j);
                pb(tmp);
                goto tryAgain;
            }
        }
    }

//    cout<<"meow?"<<endl;

    big.clear();
    for(int i=fst;i!=0;i=bak[i]){
        big.push_back(ary[i]);
    }

    sort(big.begin(),big.end(),[](const block &a,const block &b)->bool{
         if(a.x1==555)return 0;
         if(b.x1==555)return 1;
         int aa=(a.x2-a.x1+1)*(a.y2-a.y1+1);
         int ba=(b.x2-b.x1+1)*(b.y2-b.y1+1);
         if(aa!=ba)return aa>ba;
         if(a.x1!=b.x1)return a.x1<b.x1;
         return a.y1<b.y1;
    });
    for(auto i:big){
        if(i.x1==555)break;
        cout<<i.x1+1<<" "<<i.y1+1<<" "<<i.x2+1<<" "<<i.y2+1<<endl;
    }
}
