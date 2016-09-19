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

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int n;cin>>n;
    ull now=2;
    for(ull i=1;i<=n;i++){
        cout<<((i+1)*i*(i+1)-now)<<endl;
        now=i;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;;j++){
    //         if(!(((j*(i+1))*(j*(i+1))-now)%i)){
    //             cout<<"j="<<j<<"!,";
    //             cout<<((j*(i+1))*(j*(i+1))-now)/i<<endl;
    //             now=j*(i+1);
    //             break;
    //         }
    //     }
    // }
}
