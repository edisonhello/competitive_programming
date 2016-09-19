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

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

int n;
set<int> s;
int pos[3];

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    n=rit();
    for(int i=0;i<n;i++){
        int t=rit();
        s.insert(t);
    }

    if(s.size()>3){
        cout<<"NO\n";
        return 0;
    }
    if(s.size()<3){
        cout<<"YES\n";
        return 0;
    }
    int i=0;
    for(auto a=s.begin();a!=s.end();a++,i++){
        pos[i]=*a;
    }

    // cout<<pos[0]<<pos[1]<<pos[2]<<endl;
    if(abs(pos[2]-pos[1])==abs(pos[1]-pos[0])){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}
