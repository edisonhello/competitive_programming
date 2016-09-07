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

int n,k,ff;
int m[1500055];
const int z=500000,zz=1000000;

int _f(int x){
    if(x==m[x])return x;
    return m[x]=_f(m[x]);
}

void _u(int x,int y){
    m[_f(x)]=_f(y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        m[i]=i;
        m[i+z]=i+z;
        m[i+zz]=i+zz;
    }
    for(int i=0;i<k;i++){
        int d,x,y;
        cin>>d>>x>>y;
        if(x>n || y>n || x==y){
            ff++;
            continue;
        }
        if(k==1){
            if(_f(x)==_f(y+z)||_f(x)==_f(y+zz)||_f(x+z)==_f(y)||_f(x+z)==_f(y+zz)||_f(x+zz)==_f(y)||_f(x+zz)==_f(y+z)){
                ff++;
                continue;
            }
            _u(x,y);
            _u(x+z,y+z);
            _u(x+zz,y+zz);
        }
        else if(k==2){
            if(_f(x)==_f(y)||_f(x+z)==_f(y+z)||_f(x+zz)==_f(y+zz)){
                ff++;
                continue;
            }
            _u(x,y+z);
            _u(x+z,y+zz);
            _u(x+zz,y);
        }
    }
    cout<<ff<<endl;
}
