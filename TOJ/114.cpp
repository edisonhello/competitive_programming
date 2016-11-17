#include<iostream>
using namespace std;
int mp[5][6];
int main(){
    for(int i=0;i<5;++i){
        for(int j=0;j<6;++j){
            cin>>mp[i][j];
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<6;++j){
            if(mp[i][j]==mp[i+1][j]&&mp[i+1][j]==mp[i+2][j]){
                cout<<"Yes\n";
                return 0;
            }
        }
    }
    for(int i=0;i<5;++i){
        for(int j=0;j<4;++j){
            if(mp[i][j]==mp[i][j+1]&&mp[i][j+1]==mp[i][j+2]){
                cout<<"Yes\n";
                return 0;
            }
        }
    }
    cout<<"No\n";
}
