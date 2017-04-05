#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second

long long s;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>s;

    if(s<=2){
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=1;2*i+1<=s;i++){
        long long sa,sb,sc;
        sa = (ll)(2*i*i+2*i+1);
        sb = (ll)(2*i*i+2*i);
        sc = (ll)(2*i+1);
        if(s%sa == 0){
            cout<<sb*s/sa<<' '<<sc*s/sa<<endl;
            return 0;
        }
        else if(s%sb == 0){
            cout<<sa*s/sb<<' '<<sc*s/sb<<endl;
            return 0;
        }
        else if(s%sc == 0){
            cout<<sa*s/sc<<' '<<sb*s/sc<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
