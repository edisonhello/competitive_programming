#include<utility>
#include<vector>
#include<stdio.h>
#include<algorithm>
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

int n,m,q;
vector<pair<int,int> > h;
bool self[10000007];

// int _f(int a,int b){
//     int l=0,r=h.size();
//     pii t=MP(a,b);
//     while(r-l>1){
//         int m=(l+r)/2;
//         if(t==h[m])return 1;
//         if(t>h[m])l=m;
//         else r=m;
//     }
//     if(t==h[m])return 1;
//     return 0;
// }

int main(){
    n=rit(),m=rit(),q=rit();
    for(int i=0;i<m;i++){
        int a=rit(),b=rit();
        if(a==b){
            self[a]=1;
            continue;
        }
        if(a>b)swap(a,b);
        h.PB(MP(a,b));
        // h.PB(MP(b,a));
    }
    sort(h.begin(),h.end());
    for(int i=0;i<q;i++){
        int a=rit(),b=rit();
        if(a==b){
            if(self[a]){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
            continue;
        }
        if(a>b)swap(a,b);
        if(binary_search(h.begin(),h.end(),MP(a,b))){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
}
