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

int n,w,h,tot,mxx[20008];
// bool gone[20008][20008];
vector<pii> rs;


int _(int pt,int tot){
    // cout<<"_ pt="<<pt<<",tot="<<tot<<endl;
    if(mxx[pt]!=-1){
        // cout<<"has val="<<mxx[pt]<<",return"<<endl;
        return mxx[pt];
    }
    pii &now=rs[pt];
    int mx=0;
    for(int i=pt-1;i>=0;i--){
        if(rs[i].X<now.X && rs[i].Y<now.Y){
            mx=max(mx,_(i,tot+1));
        }
    }
    return mxx[pt]=tot+mx;
}

int main(){

    int t=rit();
    while(t--){
        n=rit();
        rs.clear();
        memset(mxx,-1,sizeof(mxx));
        for(int i=0;i<n;i++){
            w=rit();
            h=rit();
            rs.PB(MP(w,h));
        }
        sort(rs.begin(),rs.end());

        /*for(int i=0;i<rs.size();i++){
            cout<<"i="<<i<<", X,Y="<<rs[i].X<<","<<rs[i].Y<<endl;
        }*/

        int mx=0;
        for(int i=0;i<rs.size();i++){
            // cout<<"going i="<<i<<endl;
            mxx[i]=_(i,1);
            mx=max(mxx[i],mx);
            // cout<<"gone i="<<i<<", val="<<mxx[i]<<endl;
        }
        printf("%d\n",mx);
    }
}
