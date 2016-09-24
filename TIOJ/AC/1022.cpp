#include<queue>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct p{
    int x,y,l;
};

int k,m,n,a[1000][1000],i,j,t;
char c;
queue<p> q;
bool gone[1000][1000];

inline int rit(){
    t=0;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t;
}


int main(){
    k=rit();
    while(k--){
        m=rit(),n=rit();
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                a[i][j]=rit();
            }
        }
        while(q.size()) q.pop();
        q.push({0,0,0});
        memset(gone,0,sizeof(gone));
        gone[0][0]=1;
        while(q.size()){
            if(q.front().x==m-1 && q.front().y==n-1) break;
            // cout<<q.front().x<<" "<< q.front().y<<" "<<q.front().l<<endl;
            if(q.front().x>0   && abs(a[q.front().x-1][q.front().y]-a[q.front().x][q.front().y])<=5 && !gone[q.front().x-1][q.front().y]){q.push({q.front().x-1,q.front().y,q.front().l+1});gone[q.front().x-1][q.front().y]=1;}
            if(q.front().x<m-1 && abs(a[q.front().x+1][q.front().y]-a[q.front().x][q.front().y])<=5 && !gone[q.front().x+1][q.front().y]){q.push({q.front().x+1,q.front().y,q.front().l+1});gone[q.front().x+1][q.front().y]=1;}
            if(q.front().y>0   && abs(a[q.front().x][q.front().y-1]-a[q.front().x][q.front().y])<=5 && !gone[q.front().x][q.front().y-1]){q.push({q.front().x,q.front().y-1,q.front().l+1});gone[q.front().x][q.front().y-1]=1;}
            if(q.front().y<n-1 && abs(a[q.front().x][q.front().y+1]-a[q.front().x][q.front().y])<=5 && !gone[q.front().x][q.front().y+1]){q.push({q.front().x,q.front().y+1,q.front().l+1});gone[q.front().x][q.front().y+1]=1;}
            q.pop();
        }
        printf("%d\n",q.front().l);
    }
}
