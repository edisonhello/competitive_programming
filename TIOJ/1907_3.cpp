#include<vector>
#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;
#define pii pair<int,int>
#define X first
#define Y second

int n,w,h,i,t,tt;
char c;
vector<pii> rs,B;

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


bool cmp(const pii &a,const pii &b){
    if(a.X==b.X && a.Y>b.Y)return 1;
    return a.X<b.X;
}
bool cmpp(const pii &a,const pii &b){
    return a.Y<b.Y;
}

inline int LIS(){
    B.clear();
    B.push_back(rs[0]);
    for(i=1;i<n;i++){
        if(cmpp(B.back(),rs[i])){
            B.push_back(rs[i]);
        }
        else{
            *lower_bound(B.begin(),B.end(),rs[i],cmpp) = rs[i];
        }
    }
    return B.size();
}

int main(){
    tt=rit();
    while(tt--){
        n=rit();
        rs.clear();
        for(i=0;i<n;i++){
            w=rit();
            h=rit();
            rs.push_back({w,h});
        }
        sort(rs.begin(),rs.end(),cmp);
        printf("%d\n",LIS());
    }
}
