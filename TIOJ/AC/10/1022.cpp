#include<queue>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct p{
    int x,y,l;
};

int k,m,n,a[100][100],t;
char c;
queue<p> q;
bool gone[100][100];

inline int rit(){
    t=0;
    do{
        c=getchar_unlocked();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0'&&c<='9');
    return t;
}


int main(){
    k=rit();
    while(k--){
        m=rit(),n=rit();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                a[i][j]=rit();
            }
        }
        while(q.size()) q.pop();
        q.push({0,0,0});
        memset(gone,0,sizeof(gone));
        gone[0][0]=1;
        while(q.size()){
            auto qf=q.front();
            if(qf.x==m-1 && qf.y==n-1) break;
            // cout<<qf.x<<" "<< qf.y<<" "<<qf.l<<endl;
            if(qf.x>0   && abs(a[qf.x-1][qf.y]-a[qf.x][qf.y])<=5 && !gone[qf.x-1][qf.y]){q.push({qf.x-1,qf.y,qf.l+1});gone[qf.x-1][qf.y]=1;}
            if(qf.x<m-1 && abs(a[qf.x+1][qf.y]-a[qf.x][qf.y])<=5 && !gone[qf.x+1][qf.y]){q.push({qf.x+1,qf.y,qf.l+1});gone[qf.x+1][qf.y]=1;}
            if(qf.y>0   && abs(a[qf.x][qf.y-1]-a[qf.x][qf.y])<=5 && !gone[qf.x][qf.y-1]){q.push({qf.x,qf.y-1,qf.l+1});gone[qf.x][qf.y-1]=1;}
            if(qf.y<n-1 && abs(a[qf.x][qf.y+1]-a[qf.x][qf.y])<=5 && !gone[qf.x][qf.y+1]){q.push({qf.x,qf.y+1,qf.l+1});gone[qf.x][qf.y+1]=1;}
            q.pop();
        }
        printf("%d\n",q.front().l);
    }
}
