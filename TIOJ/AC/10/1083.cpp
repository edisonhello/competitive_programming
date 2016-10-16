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

int rit_t,rit_k;
char rit_c;
inline int rit();

string a[45];

void init(){
    a[1]="1";
    a[2]="11";
    a[3]="21";
    stringstream ss;
    string t;
    for(int i=4;i<43;++i){
        int cnt=0;
        for(int j=1;j<(int)a[i-1].length();++j){
            ++cnt;
            if(a[i-1][j]!=a[i-1][j-1]){
                ss.clear();
                ss<<cnt;
                ss>>t;
                a[i]+=t;
                a[i]+=a[i-1][j-1];
                cnt=0;
            }
        }
        ++cnt;
        ss.clear();
        ss<<cnt;
        ss>>t;
        a[i]+=t;
        a[i]+=a[i-1][a[i-1].length()-1];
        cnt=0;
        // cout<<"get i="<<i<<" "<<a[i]<<endl;
    }
}
int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    init();
    int n;while(cin>>n,n){
        cout<<a[n].length()<<" ";
        cout<<fixed<<setprecision(6)<<(ld)a[n-1].length()/(ld)a[n].length()<<'\n';
    }
}

inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
