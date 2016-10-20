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

set<int> m;
int a[2005];
int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    int n;
    while(cin>>n){
        // cout<<"jizz"<<endl;
        m.clear();
        MS0(a);
        for(int i=0;i<n;++i){
            cin>>a[i];
            if(a[i]==0)a[i]=1;
            m.insert(a[i]);
            // cout<<a[i]<<" "<<m[a[i]]<<endl;
        }
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(abs((ld)(round(sqrt((ld)(a[i]*a[i]+a[j]*a[j]))))-sqrt((ld)(a[i]*a[i]+a[j]*a[j])))>0.00002)continue;
                auto trd=m.find((ll)(round(sqrt((ld)(a[i]*a[i]+a[j]*a[j])))));
                if(trd==m.end())continue;
                ++ans;
                // cout<<fst->X<<" "<<snd->X<<" "<<trd->X<<endl;;
            }
        }
        printf("%d\n",ans);
    }
}
