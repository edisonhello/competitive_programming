#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define X first
#define Y second
#define S(x) (int)(x).size()
#define rz(x) reserve(x)
#define PB(x) push_back(x)
#define pii pair<int,int>
#define vint vector<int>
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// #define getchar getchar_unlocked
// #define putchar putchar_unlocked
#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

struct P{char f;int n;};
bool operator < (const P &a,const P &b){
    if(a.n!=b.n)return a.n>b.n;
    else return a.f>b.f;
}
P a[5000];

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].f>>a[i].n;
    }
    sort(a,a+n);
    int s;cin>>s;
    cout<<a[s-1].f<<" "<<a[s-1].n<<endl;
}
