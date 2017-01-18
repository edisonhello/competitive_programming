#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int G[15][15],bt[15][15],want[15];

vector<int> nowmnl,tmp;
int mn;

void cmp(){
    for(int i=0;i<(int)min(nowmnl.size(),tmp.size());++i){
        if(tmp[i]<nowmnl[i]){
            nowmnl=tmp;
            return;
        }
        if(tmp[i]>nowmnl[i])return;
    }
    if(tmp.size()<nowmnl.size())nowmnl=tmp;
}
void BT(int i,int j){
    tmp.push_back(i);
    while(bt[i][j]!=j){
        // cout<<i<<" "<<j<<" "<<bt[i][j]<<endl;
        i=bt[i][j];
        tmp.push_back(i);
    }
}

main(){
    int n,m,a,b,t,i,j,k,len;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&a,&b,&t);
        G[a][b]=G[b][a]=t;
    }
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            if(!G[i][j])G[i][j]=(1<<29);
            bt[i][j]=j;
        }
    }
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            if(i==j){G[i][j]=0;continue;}
            for(k=0;k<n;++k){
                if(G[i][k]+G[k][j]<G[i][j]){
                    G[j][i]=G[i][j]=G[i][k]+G[k][j];
                    bt[i][j]=bt[j][i]=k;
                }
            }
        }
    }
    //
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         printf("%d ",G[i][j]);
    //     }
    //     puts("");
    // }
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         printf("%d ",bt[i][j]);
    //     }
    //     puts("");
    // }

    scanf("%d",&k);
    for(i=0;i<k;++i)scanf("%d",&want[i]);
    sort(want+1,want+k);
    mn=0x7f7f7f7f;
    do{
        tmp.clear();
        len=0;
        for(i=1;i<k;++i){
            len+=G[want[i-1]][want[i]];
        }
        if(len>mn)continue;
        for(i=1;i<k;++i){
            BT(want[i-1],want[i]);
        }
        tmp.push_back(want[k-1]);
        if(len<mn){
            nowmnl=tmp;
            mn=len;
        }
        else if(len==mn){
            cmp();
        }
    }while(next_permutation(want+1,want+k));

    printf("Minimum travel distance: %d\nTravel route:",mn);
    for(int i=0;i<(int)nowmnl.size();++i){
        if(i && nowmnl[i-1]==nowmnl[i])continue;
        printf(" %d",nowmnl[i]);
    }
    puts("");
}
