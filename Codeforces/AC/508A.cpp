#include<bits/stdc++.h>
using namespace std;

bool mp[1010][1010];

inline bool jiz(int x,int y){
    return mp[x][y] && mp[x+1][y] && mp[x][y+1] && mp[x+1][y+1];
}
inline bool jizz(int x,int y){
    return jiz(x-1,y-1) || jiz(x,y-1) | jiz(x-1,y) | jiz(x,y);
}

int main(){
    int x,y; cin>>x>>x>>x;
    int cnt=0;
    while(cin>>x>>y){
        ++cnt;
        mp[x][y]=1;
        if(jizz(x,y)){cout<<cnt<<endl; exit(0);}
    }
    cout<<0<<endl;
}
