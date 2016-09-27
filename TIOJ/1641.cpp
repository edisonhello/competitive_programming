#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

struct stu{
    int X;
    ld Y;
    friend bool operator > (const stu &a,const stu &b){
        return a.Y>b.Y;
    }
    stu(int x,ld y){
        this->X=x;
        this->Y=y;
    }
};

int n,m,s,t;
vector<stu> G[10005];

bool gone[10005];
long double mn;
void DFS(int now,int dis,long double c){
    if(now==dis){
        // cout<<c<<endl;
        mn=min(mn,c);
        // cout<<mn<<endl;
        return;
    }
    gone[now]=1;

    for(int i=0;i<(int)G[now].size();i++){
        if(!gone[G[now][i].X]){
            DFS(G[now][i].X,dis,c+G[now][i].Y);
        }
    }
    gone[now]=0;
}

int main(){
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++){
        int ai,bi;
        ld ci;
        cin>>ai>>bi>>ci;
        ld cd=log10((ld)(ci+1.0));
        // cout<<cd<<endl;
        G[ai].push_back({bi,cd});
    }

    mn=100000.0;DFS(s,t,0.0);
    // ld res=dij(s,t);
    // cout<<mn<<endl;
    printf("%.2lfe+%03d\n",pow(10.0,mn-(int)mn),(int)mn);
}













// ld dij(int sour,int dist){
//     ld d[10005];
//     bool v[10005]={0};
//     // for(int i=0;i<10005;i++)d[i]=(ld)99999.0;
//     priority_queue<stu,vector<stu>,greater<stu>> pq;
//     fill(d,d+10005,100000.0);
//     d[sour]=0;
//     pq.push({sour,0.0});
//     for(int ppp=0;ppp<n;ppp++){
//         while(pq.size() && v[pq.top().X]){
//             pq.pop();
//         }
//         if(!pq.size()){
//             break;
//         }
//         int nowc=pq.top().X;
//         v[nowc]=1;
//         // cout<<"join:nowc:"<<nowc<<endl;
//         for(int i=0;i<(int)G[nowc].size();i++){
//             if(!v[G[nowc][i].X] && d[nowc]+G[nowc][i].Y < d[G[nowc][i].X]){
//                 d[G[nowc][i].X]=d[nowc]+G[nowc][i].Y;
//                 pq.push({G[nowc][i].X,d[G[nowc][i].X]});
//             }
//         }
//     }
//     return d[dist];
// }
