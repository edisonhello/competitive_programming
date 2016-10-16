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

int n,cnt0;
int s[1000005][2];
bool _1s,_0s;
ll tot,dis;

int main(){
    while(scanf("%d",&n)!=EOF,n){
        MS0(s);  //case 0!
        _0s=_1s=0;
        tot=0;
        dis=0;
        cnt0=0;
        for(int i=0;i<n;++i){
            s[i][0]=rit(),s[i][1]=rit();
            if(s[i][0]==0&&s[i][1]==0){
                ++tot;
            }
            if(s[i][0]>s[i][1]){
                tot+=s[i][1];
                ++_1s;
            }
            else{
                tot+=s[i][0];
                ++_0s;
            }
        }
        if(!_1s || !_0s){
            dis=(1ll<<60);
            for(int i=0;i<n;++i){
                dis=min(dis,((ll)abs(s[i][0]-s[i][1]))==0ll?(1ll<<60):(ll)abs(s[i][0]-s[i][1]);
            }
        }
        printf("%lld\n",tot+dis);
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
