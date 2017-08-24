#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
using namespace std;
const int MX = 405;
//bool mp[MX][MX];
//bool gone[MX];
bool **mp,*gone;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,l;cin>>n>>l;
    mp=new bool*[n+1];
    gone=new bool[n+1];
    for(int i=0;i<n+1;i++){
        mp[i]=new bool[n+1];
        gone[i]=0;
        for(int j=0;j<n+1;j++){
            mp[i][j]=0;
        }
    }
    for(int i=0;i<l;i++){
        int _,__;cin>>_>>__;
        mp[_][__]=mp[__][_]=1;
    }
//cout<<"123"<<endl;
    //who has the pair[1][n]
    if(mp[1][n]){
        queue<pair<int,int> > q;
        q.push(make_pair(1,0));
        while(q.size()){
            int now=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(now==n){ //cout<<"jizz"<<endl;
                cout<<dis<<endl;
                return 0;
            }
            gone[now]=1;
            for(int i=1;i<=n;i++){       //cout<<i<<endl;
                if(mp[now][i]==0 && gone[i]==0){//cout<<now<<"->"<<i<<" dis"<<dis<<endl;
                    q.push(make_pair(i,dis+1));
                }
            }
        }
        cout<<-1<<endl;
        return 0;
    }
    else{
        queue<pair<int,int> > q;
        q.push(make_pair(1,0));
        while(q.size()){
            int now=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(now==n){
                cout<<dis<<endl;
                return 0;
            }
            gone[now]=1;
            for(int i=1;i<=n;i++){       //printf("now at %d, i=%d\n",now,i);
                if(mp[now][i]==1 && gone[i]==0){
                    q.push(make_pair(i,dis+1)); //printf("now%d->i%d\n",now,i);
                }
            }
        }
        cout<<-1<<endl;
        return 0;
    }
}
