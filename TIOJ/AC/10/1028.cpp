#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
#define int long long

int G[15][15],bt[15][15],want[15];

vector<int> nowmnl,tmp;
int mn;

void BT(int i,int j){
    if(bt[i][j]!=-1){
        BT(i,bt[i][j]);
        BT(bt[i][j],j);
    }
    else tmp.push_back(i);
    return;
    tmp.push_back(i);
    while(bt[i][j]!=j){
        // cout<<i<<" "<<j<<" "<<bt[i][j]<<endl;
        i=bt[i][j];
        tmp.push_back(i);
    }
}

main(){
    int n,m,a,b,t,i,j,k,len;
    scanf("%lld%lld",&n,&m);
    while(m--){
        scanf("%lld%lld%lld",&a,&b,&t);
        G[a][b]=G[b][a]=t;
    }
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            if(!G[i][j])G[i][j]=(1ll<<59);
            bt[i][j]=-1;
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
                /*else if(G[i][k]+G[k][j]==G[i][j]){
                    if(k<bt[i][j])bt[i][j]=k;
                    if(k<bt[j][i])bt[j][i]=k;
                }*/
            }
        }
    }
    //
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         printf("%lld ",G[i][j]);
    //     }
    //     puts("");
    // }
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         printf("%lld ",bt[i][j]);
    //     }
    //     puts("");
    // }

    bool wlist[15]={0},first=0;
    scanf("%lld",&k); while(k--){
        int t; scanf("%lld",&t);
        if(!first)want[0]=t;
        else wlist[t]=1;
        first=1;
    } k=1; for(int i=0;i<15;++i){
        if(wlist[i])want[k++]=i;
    }
    sort(want+1,want+k);
    mn=0x7f7f7f7f7f7f7f7f;
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
            for(int i=0;i<min(nowmnl.size(),tmp.size());++i){
                if(tmp[i]<nowmnl[i]){
                    nowmnl=tmp;
                    break;
                }
                if(tmp[i]>nowmnl[i])break;
            }
        }
    }while(next_permutation(want+1,want+k));

    printf("Minimum travel distance: %lld\nTravel route:",mn);
    for(int i=0;i<(int)nowmnl.size();++i){
        if(i && nowmnl[i-1]==nowmnl[i])continue;
        printf(" %lld",nowmnl[i]);
    }
    puts("");
}
