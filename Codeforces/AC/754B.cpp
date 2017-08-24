#include<iostream>
using namespace std;

string s[5];

bool canWin(char a,char b,char c){
    char j='o';
    if(a==j||b==j||c==j)return 0;
    int cnt=0;j='x';
    if(a==j)++cnt;
    if(b==j)++cnt;
    if(c==j)++cnt;
    return cnt==2;
}

int main(){
    for(int i=0;i<4;++i)cin>>s[i];

    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(j<2 && canWin(s[i][j],s[i][j+1],s[i][j+2])){cout<<"YES\n";return 0;}
            if(j>1 && canWin(s[i][j],s[i][j-1],s[i][j-2])){cout<<"YES\n";return 0;}
            if(i<2 && canWin(s[i][j],s[i+1][j],s[i+2][j])){cout<<"YES\n";return 0;}
            if(i>1 && canWin(s[i][j],s[i-1][j],s[i-2][j])){cout<<"YES\n";return 0;}
            if(i<2 && j<2 &&
                canWin(s[i][j],s[i+1][j+1],s[i+2][j+2])){cout<<"YES\n";return 0;}
            if(i>1 && j>1 &&
                canWin(s[i][j],s[i-1][j-1],s[i-2][j-2])){cout<<"YES\n";return 0;}
            if(i<2 && j>1 &&
                canWin(s[i][j],s[i+1][j-1],s[i+2][j-2])){cout<<"YES\n";return 0;}
            if(i>1 && j<2 &&
                canWin(s[i][j],s[i-1][j+1],s[i-2][j+2])){cout<<"YES\n";return 0;}
        }
    }
    cout<<"NO\n";
}
