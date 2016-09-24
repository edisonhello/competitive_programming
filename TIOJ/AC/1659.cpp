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
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

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
}

vector<int> p;
int n,tryto,i;
bool d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p.PB(2);
    p.PB(3);
    p.PB(5);
    for(tryto=6;tryto<=5123;tryto++){
        d=0;
        for(i=2;i*i<=tryto;i++){
            if(tryto%i==0){
                d=1;
                break;
            }
        }
        if(!d){
            p.PB(tryto);
        }
    }
    while(cin>>n){
        cout<<"primes between 1 ~ "<<n<<":";
        for(i=0;p[i]<=n && i<(int)p.size();i++){
            cout<<' '<<p[i];
        }
        cout<<'\n';
    }
}
