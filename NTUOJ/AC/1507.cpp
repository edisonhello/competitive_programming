#include<bits/stdc++.h>
using namespace std;
#define map MMMAAAPPP

struct map{
    vector<string> v;
    map(){ v.resize(8); }
    string& operator[](const int x){ return v[x]; }
    bool operator<(const map &b)const{ return v<b.v; }
};

bool isblock(char c){
    return c=='A' || c=='B' || c=='C' || c=='D';
}

map goleft(map now){
    while(1){
        bool move=0;
        for(int i=0;i<7;++i){
            for(int j=6;j>=1;--j){
                if(isblock(now[i][j]) && now[i+1][j]==now[i][j] && now[i][j+1]==now[i][j] && now[i][j-1]=='.' && now[i+1][j-1]=='.'){
                    now[i][j-1]=now[i+1][j-1]=now[i][j];
                    now[i][j+1]=now[i+1][j+1]='.';
                    move=1;
                }
            }
        }
        if(!move)return now;
    }
}
map goright(map now){
    while(1){
        bool move=0;
        for(int i=0;i<7;++i){
            for(int j=0;j<6;++j){
                if(isblock(now[i][j]) && now[i+1][j]==now[i][j] && now[i][j+1]==now[i][j] && now[i][j+2]=='.' && now[i+1][j+2]=='.'){
                    now[i][j+2]=now[i+1][j+2]=now[i][j];
                    now[i][j]=now[i+1][j]='.';
                    move=1;
                }
            }
        }
        if(!move)return now;
    }
}
map goup(map now){
    while(1){
        bool move=0;
        for(int i=6;i>=1;--i){
            for(int j=0;j<7;++j){
                if(isblock(now[i][j]) && now[i+1][j]==now[i][j] && now[i][j+1]==now[i][j] && now[i-1][j]=='.' && now[i-1][j+1]=='.'){
                    now[i-1][j]=now[i-1][j+1]=now[i][j];
                    now[i+1][j]=now[i+1][j+1]='.';
                    move=1;
                }
            }
        }
        if(!move)return now;
    }
}
map godown(map now){
    while(1){
        bool move=0;
        for(int i=0;i<6;++i){
            for(int j=0;j<7;++j){
                if(isblock(now[i][j]) && now[i+1][j]==now[i][j] && now[i][j+1]==now[i][j] && now[i+2][j]=='.' && now[i+2][j+1]=='.'){
                    now[i+2][j]=now[i+2][j+1]=now[i][j];
                    now[i][j]=now[i][j+1]='.';
                    move=1;
                }
            }
        }
        if(!move)return now;
    }
}

int main(){
    int t; cin>>t; for(int tt=1;tt<=t;++tt){
        map o;
        for(int i=0;i<8;++i)cin>>o[i];
        queue<map> q; q.push(o);
        set<map> st; 
        auto add=[&](const map &x){
            if(st.find(x)==st.end()){
                st.insert(x);
                q.push(x);
            }
        };
        while(q.size()){
            map now=q.front(); q.pop();
            map left=goleft(now);
            map right=goright(now);
            map up=goup(now);
            map down=godown(now);
            add(left);
            add(right);
            add(up);
            add(down);
        }
        cout<<"Case "<<tt<<": "<<st.size()<<endl;
    }
}
