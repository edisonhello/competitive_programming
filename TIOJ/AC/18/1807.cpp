#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
#define DE cout<<"de"<<endl;

int m,n,t,i,a,b;
map<int,int> mp;
bool con[1003][1003];
char c;

inline int rit(){
    t=0;
    do{
        c=getchar_unlocked();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0'&&c<='9');
    return t;
};


inline int id(int _){
    auto a=mp.find(_);
    if(a==mp.end()){
        mp[_]=mp.size();
    }
    return mp[_];
}

int main(){
    m=rit(),n=rit();
    if(n>m*m){
        printf("Yes\n");
        return 0;
    }
    for(i=0;i<n;i++){
        a=rit(),b=rit();
        if(a==b){
            printf("Yes\n");
            return 0;
        }
        a=id(a),b=id(b);
        if(con[a][b]){
            printf("Yes\n");
            return 0;
        }
        con[a][b]=con[b][a]=1;
    }
    printf("yes\n");
}
