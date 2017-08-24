#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))

int rit_t,rit_k;
char rit_c;
inline int rit();
int m,n;
int a[2005];
int a_tot[2005],b_tot[2005];
vector<pair<int,int>> give;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<=m){
            a_tot[a[i]]++;
        }
    }
    int getmx=n/m;
    for(int i=1;i<=m;i++){
        if(a_tot[i]<getmx){
            give.push_back({i,getmx-a_tot[i]});
            // cout<<"PB,"<<i<<" "<<a_tot[i]<<endl;
        }
    }
    // cout<<give.size()<<endl;
    int cnt=0,pt=0;
    for(int i=1;i<=n && pt<(int)give.size();i++){
        if(a[i]<=m && b_tot[a[i]]<=getmx){
            b_tot[a[i]]++;
        }
        else{
            cnt++;
            a[i]=give[pt].X;
            b_tot[give[pt].X]++;
            give[pt].Y--;
            if(give[pt].Y==0)pt++;
        }
    }
    cout<<getmx<<" "<<cnt<<endl;
    for(int i=1;i<=n;i++){
        if(i-1)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
}


inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar_unlocked();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar_unlocked();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
