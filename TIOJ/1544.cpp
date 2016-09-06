#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ull t;
    string a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        if(a.length()!=b.length())cout<<(a.length()>b.length()?0:1)<<endl;
        else{
            int ced=0;
            for(int i=0;i<a.length();i++){
                if(a[i]!=b[i]){
                    cout<<(a[i]>b[i]?0:1)<<endl;
                    ced=1;
                    break;
                }
            }
            if(!ced)cout<<1<<endl;
        }

    }

}

