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


int ts;
int n,m,st,fi;
int hei[10004],near[10004];
vector<int> G[10004];
void CLEAR(){
    for(int i=0;i<n;i++){
        G[i].clear();
    }
    n=0,m=0,st=0,fi=0x7fedcba9;
    MS0(hei);
    MSM(near);
}
void READ(){
    cin>>n>>m>>st;
    for(int i=0;i<n;i++){
        cin>>hei[i];
        if(hei[i]<fi){
            fi=hei[i];
            // cout<<"fi update:"<<fi<<endl;
        }
    }
    for(int i=0;i<m;i++){
        int s,t;
        cin>>s>>t;
        if(hei[(near[s]==-1?s:near[s])]>hei[t]){
            near[s]=t;
        }
        if(hei[(near[t]==-1?t:near[t])]>hei[s]){
            near[t]=s;
        }
        G[s].PB(t);
        G[t].PB(s);
    }
}
void SOL(){
    int CAR=0x7f7f7f7f;{
        int now=st;
        int cnt=0;
        while(hei[now]!=fi&&near[now]!=-1){
            // cout<<"CAR: going "<<now<<endl;
            cnt++;
            now=near[now];
        }
        if(hei[now]==fi){
            CAR=cnt;
        }
    }
    int WAK=0x7f7f7f7f;{
        queue<pair<int,int>> bfs;
        bitset<10004> gone;
        bfs.push({st,0});
        gone[st]=1;
        while(bfs.size()){
            auto fnt=bfs.front();
            bfs.pop();
            if(hei[fnt.X]==fi){
                WAK=fnt.Y*6;
                break;
            }
            for(int i=0;i<(int)G[fnt.X].size();i++){
                if(!gone[G[fnt.X][i]]){
                    gone[G[fnt.X][i]]=1;
                    bfs.push({G[fnt.X][i],fnt.Y+1});
                }
            }
        }
    }
    // cout<<CAR<<" "<<WAK<<endl;
    if(WAK==0x7f7f7f7f){
        cout<<"Call 119!\n";
    }
    else if(CAR==0x7f7f7f7f){
        cout<<WAK<<'\n';
    }
    else{
        cout<<abs(WAK-CAR)<<'\n';
    }
}
int main(){
    cin>>ts;
    for(int cs=1;cs<=ts;cs++){
        cout<<"Case #"<<cs<<": ";
        CLEAR();
        READ();
        SOL();
    }
}
