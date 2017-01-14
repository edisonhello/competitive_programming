#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

struct inf{int x,y,d;};

string mp[1005];
vector<queue<inf>> fir,fri;
bool gone[7][1005][1005],out[7];

int main(){
    int ts;cin>>ts;while(ts--){
        for(auto &Q:fir)while(Q.size())Q.pop();
        for(auto &Q:fri)while(Q.size())Q.pop();
        fir.clear(),fri.clear();
        memset(out,0,sizeof(out));
        memset(gone,0,sizeof(gone));

        int n,m;cin>>n>>m;
        mp[0]=mp[n+1]="OO";
        for(int i=1;i<=n;++i){
            cin>>mp[i];
            mp[i]="O"+mp[i]+"O";
            for(int j=1;j<=m;++j){
                if(mp[i][j]=='F'){
                    queue<inf> tq;
                    tq.push({i,j,0});
                    fir.push_back(tq);
                    mp[i][j]='#';
                }
                else if(mp[i][j]=='J'){
                    queue<inf> tq;
                    tq.push({i,j,0});
                    gone[tq.size()][i][j]=1;
                    fri.push_back(tq);
                }
            }
        }
        for(int i=0;i<m;++i)mp[0]+="O",mp[n+1]+="O";

        // for(int i=0;i<=n+1;++i)cout<<mp[i]<<endl;

        for(int t=1;fri.size();++t){
            // cout<<"going to t="<<t<<endl;
            for(auto &Q:fir){
                while(Q.size() && Q.front().d<t){
                    inf P=Q.front();Q.pop();
                    if(mp[P.x-1][P.y]!='O' && mp[P.x-1][P.y]!='#'){mp[P.x-1][P.y]='#';Q.push({P.x-1,P.y,t});}
                    if(mp[P.x][P.y-1]!='O' && mp[P.x][P.y-1]!='#'){mp[P.x][P.y-1]='#';Q.push({P.x,P.y-1,t});}
                    if(mp[P.x+1][P.y]!='O' && mp[P.x+1][P.y]!='#'){mp[P.x+1][P.y]='#';Q.push({P.x+1,P.y,t});}
                    if(mp[P.x][P.y+1]!='O' && mp[P.x][P.y+1]!='#'){mp[P.x][P.y+1]='#';Q.push({P.x,P.y+1,t});}
                }
            }
            bool sbInit=0;
            for(int i=0;i<(int)fri.size();++i){
                if(out[i])continue;
                auto &Q=fri[i];
                sbInit=1;
                while(Q.size() && Q.front().d<t){
                    // cout<<"Q.sz:"<<Q.size()<<", -> ";
                    inf P=Q.front();Q.pop();
                    // cout<<"friend"<<i<<" go to ("<<P.x<<","<<P.y<<") at "<<P.d<<" , sizeLeft:"<<Q.size()<<"\n";
                    if(mp[P.x][P.y]=='O'){
                        out[i]=1;
                        while(Q.size())Q.pop();
                    }
                    if(mp[P.x-1][P.y]!='#' && !gone[i][P.x-1][P.y]){/*cout<<"go into herea "<<P.x-1<<" "<<P.y<<endl;*/gone[i][P.x-1][P.y]=1;Q.push({P.x-1,P.y,t});}
                    if(mp[P.x][P.y-1]!='#' && !gone[i][P.x][P.y-1]){/*cout<<"go into hereb "<<P.x<<" "<<P.y-1<<endl;*/gone[i][P.x][P.y-1]=1;Q.push({P.x,P.y-1,t});}
                    if(mp[P.x+1][P.y]!='#' && !gone[i][P.x+1][P.y]){/*cout<<"go into herec "<<P.x+1<<" "<<P.y<<endl;*/gone[i][P.x+1][P.y]=1;Q.push({P.x+1,P.y,t});}
                    if(mp[P.x][P.y+1]!='#' && !gone[i][P.x][P.y+1]){/*cout<<"go into hered "<<P.x<<" "<<P.y+1<<endl;*/gone[i][P.x][P.y+1]=1;Q.push({P.x,P.y+1,t});}
                }
                if(!Q.size() && !out[i]){
                    cout<<"-1\n";
                    goto nextData;
                }
            }
            if(!sbInit){
                cout<<t-2<<endl;
                goto nextData;
            }
        }
        nextData:;
    }
}
