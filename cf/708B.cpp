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

ll _00,_01,_10,_11;
int b[1000006];

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    cin>>_00>>_01>>_10>>_11;
    float fget0=(1+sqrt(1+8*_00))/2;
    float fget1=(1+sqrt(1+8*_11))/2;

    ll _0=(ll)(fget0+0.5);
    ll _1=(ll)(fget1+0.5);
    // cout<<_0<<' '<<_1<<endl;

    if(_00==0&&_11==0){
        if(_01==1){
            cout<<"01"<<endl;
            return 0;
        }
        if(_10==1){
            cout<<"10"<<endl;
            return 0;
        }
        cout<<"0\n";
        return 0;
    }
    if(_00==0){
        if(_1*(_1-1)/2!=_11){
            cout<<"Impossible\n";
            return 0;
        }
        if(_01+_10==_1){
            ll _=_1+1;
            for(int i=0;i<_;i++) putchar(i==_10?'0':'1'); putchar('\n');
            return 0;
        }
        for(int i=0;i<_1;i++) putchar('1'); putchar('\n');
        return 0;
    }
    if(_11==0){
        if(_0*(_0-1)/2!=_00){
            cout<<"Impossible\n";
            return 0;
        }
        if(_01+_10==_0){
            ll _=_0+1;
            for(int i=0;i<_;i++) putchar(i==_01?'1':'0'); putchar('\n');
            return 0;
        }
        for(int i=0;i<_0;i++) putchar('0'); putchar('\n');
        return 0;
    }

    if(_0&&_1){
        if(_0*(_0-1)/2!=_00 || _1*(_1-1)/2!=_11){
            cout<<"Impossible\n";
            return 0;
        }

        if(_0*_1!=_01+_10){
            cout<<"Impossible\n";
            return 0;
        }
        ll _=_0+_1;
        ll ptr=_1-1;

        // for(int i=0;i<_;i++) putchar(b[i]?'0':'1'); putchar('\n');
        while(ptr>=0){
            // cout<<_0<<" "<<_1<<" "<<_01<<" "<<_10<<" ";
            // output

            if(_01>_0){
                b[ptr--]=_0;
                _01-=_0;
            }
            else{
                b[ptr--]=_01;
                _01=0;
            }
        }

        for(int i=0,c=0;i<_1;i++){
            while(c<b[i]){
                putchar('0');
                c++;
            }
            putchar('1');
        }
        return 0;
    }
}
