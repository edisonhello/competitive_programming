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
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2

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
};

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    string s;
    cin>>s;

    int chg=0;
    for(int i=0;i<(int)s.length();i++){
        if(s[i]!='a'){
            chg++;
            s[i]--;
        }
        else{
            if(chg)break;
            if(i==(int)(s.length())-1)s[i]='z';
        }
    }
    cout<<s<<endl;
}
