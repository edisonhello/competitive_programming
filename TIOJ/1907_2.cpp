#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define vint vector<int>
#define pii pair<int,int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
};

int n,w,h,tot;
vector<pii> rs,B;

bool cmp(const pii &a,const pii &b){
    if(a.X<b.X && a.Y<b.Y)return 1;
    return 0;
}

int LIS(){
    B.clear();
    B.PB(rs[0]);
    for(int i=1;i<n;i++){
        pii &Bb = B.back();
        if(rs[i].X>Bb.X && rs[i].Y>Bb.Y){
            B.PB(rs[i]);
        }
        else{
            *lower_bound(B.begin(),B.end(),rs[i],cmp) = rs[i];
        }
    }
    return B.size();
}

int main(){
    int t=rit();
    while(t--){
        n=rit();
        rs.clear();
        for(int i=0;i<n;i++){
            w=rit();
            h=rit();
            rs.PB(MP(w,h));
        }
        sort(rs.begin(),rs.end(),cmp);

        printf("%d\n",LIS());
    }
}
