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


int n;string s;
int a[25];

inline char G(const int a,const int b){return s[(a+b)%n];}
bool cmp(const int &a,const int &b){
    for(int i=0;i<n;i++){
        if(G(a,i)!=G(b,i))return G(a,i)<G(b,i);
    }
    return 0;
}

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n>>s){
        for(int i=0;i<n;i++){
            a[i]=i;
        }
        sort(a,a+n,cmp);
        // for(int i=0;i<n;++i){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        string ans;int st;
        for(int i=0;i<n;++i){
            ans+=G(a[i],n-1);
            if(a[i]==1)st=i+1;
        }
        cout<<ans<<'\n'<<st<<'\n';
    }
}
