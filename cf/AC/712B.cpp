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

string s;
int l,u;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    if(s.length()&1){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='L'){
            l++;
        }
        if(s[i]=='R'){
            l--;
        }
        if(s[i]=='U'){
            u++;
        }
        if(s[i]=='D'){
            u--;
        }
    }
    cout<<abs(abs(l)+abs(u))/2<<endl;
}
