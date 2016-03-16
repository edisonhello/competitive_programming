#include<bits/stdc++.h>




using namespace std;
int lng[505][505],n,m;
bool gone[505];
int t;
bool warp;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > que;

void solve(){
    pair<int,int> l2,last;
    int nowtime,now,prevtime=que.top().first,previ=que.top().second;
    while(1){
        nowtime = que.top().first;      //printf("time %d\n",nowtime);
        now = que.top().second;

        for(int i=1;i<=n;i++){
            if(lng[i][now]!=0 && !gone[i]){
                que.push(make_pair(nowtime + lng[i][now], i));
                gone[i] = 1;
            }
        }
//printf("jizz");

        if(que.size()==1){
            last = que.top();
            l2.first = prevtime;
            l2.second =previ;
            break;
        }

        que.pop();

        previ = now;
        prevtime = nowtime;
    }
    if(warp){printf("\n");}
    warp =1;

    if(l2.first==last.first && lng[l2.second][last.second]!=0){
        printf("System #%d\nThe last domino falls after %.1f seconds, between key dominoes %d and %d.\n",t,(float)last.first+((float)lng[l2.second][last.second]/2),last.second,l2.second);
    }
    else{
        printf("System #%d\nThe last domino falls after %.1f seconds, at key domino %d.\n",t,(float)last.first,last.second);
    }
    while(que.size())que.pop();
}

int main(){
    while(scanf("%d %d",&n,&m) && n){



            t++;
        for(int i=0;i<m;i++){
            int l,r,hv;
            scanf("%d %d %d",&l,&r,&hv);
            lng[l][r] = lng[r][l] = hv;
        }

        for(int i=1;i<=n;i++){//printf("jizz");
            if(lng[1][i]!=0){
                    gone[i] = 1;//printf("pushed %d time passed %d",i,lng[1][i]);
                que.push(make_pair(lng[1][i],i));

            }
        }
        gone[1] = 1;
        solve();






        for(int i=0;i<505;i++)gone[i]=0;
    }
}
