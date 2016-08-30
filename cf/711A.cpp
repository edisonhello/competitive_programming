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

string s[1005];

int main(){
    int n;cin>>n;
    int getans=0;
    for(int i=0;i<n;i++){
        cin>>s[i];
        if((s[i][0]=='O'&&s[i][1]=='O')&&!getans){
            getans=1;
            s[i][0]=s[i][1]='+';
        }
        else if((s[i][3]=='O'&&s[i][4]=='O')&&!getans){
            getans=1;
            s[i][3]=s[i][4]='+';
        }
    }
    if(getans){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<s[i]<<endl;
        }
    }
    else{
        cout<<"NO\n";
    }
}
