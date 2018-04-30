#include<bits/stdc++.h>
using namespace std;

int djs[100000];
int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}

bool app[1231][1231];

int main(){
    freopen("in.txt","w",stdout);
    srand(time(0));
    int n=20;
    cout<<n<<endl;
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1;i<n;++i){
        int u=0,v=0;
        while(F(u)==F(v)){
            u=rand()%n+1;
            v=rand()%n+1;
        }
        cout<<u<<" "<<v<<endl;
        U(u,v);
        app[u][v]=app[v][u]=1;
    }
    int u=0,v=0;
    do{
        u=rand()%n+1;
        v=rand()%n+1;
    }while(app[u][v]);
    cout<<u<<" "<<v<<endl;
}
