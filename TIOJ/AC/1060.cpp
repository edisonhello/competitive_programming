#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x+5)
#define X first
#define Y second
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

int g(int z){
    if(z<=2){
        return z*z-1;
    }
    else{
        return 2;
    }
}
int h(int y){
    if(y<2){
        return -1;
    }
    else{
        if(y%6==2 || y%6==5){
            return 2;
        }
        else if(y%6==3 || y%6==4){
            return 5;
        }
        else return -1;
    }
}
int f(int x){
    int hx=h(x);
    if(x>hx){
        return f(x-1)-hx;
    }
    else if(x<hx){
        int gx=g(x);
        return f(gx)-gx;
    }
    else{
        return 1;
    }
}



int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    int n=rit();

    cout<<f(n)<<endl;
}
