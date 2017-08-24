#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

inline int rit(){
    int t=0;char c;
    do{
        c=getchar();
    }while(c<'0' || c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t;
}

int n;
vector<pair<int,int> > line;
bool **mp,*gone;



int dfs(int now,int dist,int depth){
    gone[now] = 1;
        /*debug*///printf("dfs now %d dist %d depth %d\n",now,dist,depth);
    if(now == dist){    /*debug*///printf("now = dist\n return %d\n",depth);
        gone[now]=0;
        return depth;
    }

    int mn=999999;
    for(int i=0;i<n;i++){
        if(mp[now][i] && !gone[i]){
                        /*debug*///printf("found %d can go, go\n",i);

            mn = min(mn,dfs(i,dist,depth+1));
        }
    }
    gone[now]=0;
    return mn;
}


int main(){
    n=rit();
    mp = new bool*[n];
    gone = new bool[n];         /*debug*///printf("formatting\n");
    for(int i=0;i<n;i++){
        mp[i] = new bool[n];
        gone[i]=0;
        for(int j=0;j<n;j++){
            mp[i][j]=0;
        }                       /*debug*///printf("formatting... %d%%\n",i*100/n);
    }                           /*debug*///printf("format finish\n");
    for(int i=0;i<n-1;i++){
        int x=rit(),y=rit();
        line.push_back(make_pair(x-1,y-1));
        mp[x-1][y-1]=mp[y-1][x-1]=1;
                    /*debug*///printf("link made btw %d and %d , check %d\n",x,y,mp[x-1][y-1]);
    }
    int q=rit();
    while(q--){
        int com=rit();
        if(com==1){
            int id=rit();       /*debug*///printf("rec com %d, id %d, check %d\n",com,id,mp[line[id-1].F][line[id-1].S]);
            mp[line[id-1].F][line[id-1].S] = mp[line[id-1].S][line[id-1].F] = 1;
        }
        if(com==2){
            int id=rit();       /*debug*///printf("rec com %d, id %d, check line %d->%d\n",com,id,line[id-1].F,line[id-1].S);
            mp[line[id-1].F][line[id-1].S] = mp[line[id-1].S][line[id-1].F] = 0;
        }
        if(com==3){
            int start=rit(),dist=rit();
            /*t3*/if(start == dist){
                printf("0\n");
                continue;
            }
                                /*debug*///printf("rec com %d, from %d to %d, do dfs\n",com,start-1,dist-1);
            int res = dfs(start-1,dist-1,0);
                                /*debug*///printf("got res %d\n",res);
            if(res>0 &&res!=999999){
                printf("%d\n",res);
            }
            else{
                printf("-1\n");
            }
        }
    }
}
