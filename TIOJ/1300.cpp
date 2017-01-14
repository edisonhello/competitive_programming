#include<iostream>
#include<queue>
using namespace std;

struct pt{
    int x,y,t;
};

string s[15];
queue<pt> q;
int sx,sy,ex,ey;
bool v[15][15];

int main(){
    for(int i=0;i<10;++i){
        cin>>s[i];
        for(int j=0;j<9;++j){
            if(s[i][j]=='P'){
                sx=i,sy=j;
            }
            else if(s[i][j]=='E'){
                ex=i,ey=j;
            }
        }
    }
    q.push({sx,sy,0});
    v[sx][sy]=1;
    while(q.size()){
        pt t=q.front();q.pop();
        if(t.x<0 || t.y<0 || t.x>9 || t.y>8)continue;
        // cout<<t.x<<" "<<t.y<<" ("<<t.t<<")\n";
        if(t.x==ex && t.y==ey){cout<<t.t<<endl;return 0;}
        if(t.x>1 && s[t.x-1][t.y]!='S'){
            if(!v[t.x-1][t.y]){q.push({t.x-1,t.y,t.t+1});v[t.x-1][t.y]=1;}
            if(t.y<9 && s[t.x-2][t.y+1]!='S' && !v[t.x-2][t.y+1]){q.push({t.x-2,t.y+1,t.t+1});v[t.x-2][t.y+1]=1;}
            if(t.y>0 && s[t.x-2][t.y-1]!='S' && !v[t.x-2][t.y-1]){q.push({t.x-2,t.y-1,t.t+1});v[t.x-2][t.y-1]=1;}
        }
        if(t.y>1 && s[t.x][t.y-1]!='S'){
            if(!v[t.x][t.y-1]){q.push({t.x,t.y-1,t.t+1});v[t.x][t.y-1]=1;}
            if(t.x<10&& s[t.x+1][t.y-2]!='S' && !v[t.x+1][t.y-2]){q.push({t.x+1,t.y-2,t.t+1});v[t.x+1][t.y-2]=1;}
            if(t.x>0 && s[t.x-1][t.y-2]!='S' && !v[t.x-1][t.y-2]){q.push({t.x-1,t.y-2,t.t+1});v[t.x-1][t.y-2]=1;}
        }
        if(t.x<9 && s[t.x+1][t.y]!='S'){
            if(!v[t.x+1][t.y]){q.push({t.x+1,t.y,t.t+1});v[t.x+1][t.y]=1;}
            if(t.y<9 && s[t.x+2][t.y+1]!='S' && !v[t.x+2][t.y+1]){q.push({t.x+2,t.y+1,t.t+1});v[t.x+2][t.y+1]=1;}
            if(t.y>0 && s[t.x+2][t.y-1]!='S' && !v[t.x+2][t.y-1]){q.push({t.x+2,t.y-1,t.t+1});v[t.x+2][t.y-1]=1;}
        }
        if(t.y<8 && s[t.x][t.y-1]!='S'){
            if(!v[t.x][t.y+1]){q.push({t.x,t.y+1,t.t+1});v[t.x][t.y+1]=1;}
            if(t.x<10&& s[t.x+1][t.y+2]!='S' && !v[t.x+1][t.y+2]){q.push({t.x+1,t.y+2,t.t+1});v[t.x+1][t.y+2]=1;}
            if(t.x>0 && s[t.x-1][t.y+2]!='S' && !v[t.x-1][t.y+2]){q.push({t.x-1,t.y+2,t.t+1});v[t.x-1][t.y+2]=1;}
        }
    }
    cout<<0<<endl;
}
