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

map<string,int> m;

string _(string s){
    for(int i=0;i<(int)s.length();i++){
        s[i]=(s[i]-'0')%2+'0';
    }
    while(s.length()<18){
        s='0'+s;
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;cin>>n;
    char c;string s;
    while(n--){
        cin>>c>>s;
        s=_(s);
        if(c=='+')m[s]++;
        if(c=='-')m[s]--;
        if(c=='?'){
            cout<<m[s]<<endl;
        }
    }
}
