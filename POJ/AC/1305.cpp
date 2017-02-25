#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
#define rz(x) resize(x)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define endl '\n'
#define el putchar('\n')
#define spc putchar(' ')
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define CIO ios_base::sync_with_stdio(0);
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define FLH fflush(stdout)


const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

bool v[1000009];

int __gcd(int a,int b){
    if(b>a)swap(a,b);
    while(b){
        a%=b;
        swap(a,b);
    } return a;
}

int main(){
    // FIN, FOUT;
    int n;while(cin>>n && n){
        int ans=0;
        memset(v+1,0,sizeof(bool)*n);
        for(int i=1;i*i<=n;i+=2){
            for(int j=2;i*i+j*j<=n && 2*i*j<=n;j+=2){
                int a=abs(j*j-i*i),b=i*i+j*j,c=2*i*j;
                int tms=1;while(a*tms<=n && b*tms<=n && c*tms<=n){++v[a*tms],++v[b*tms],++v[c*tms],++tms;}
                // cout<<"get "<<a<<" "<<b<<" "<<c<<endl;
                if(__gcd(__gcd(a,b),c)>1)continue;
                // cout<<"is ori!"<<endl;
                ++ans;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;++i)if(!v[i])++cnt;
        cout<<ans<<" "<<cnt<<endl;
    }
}
