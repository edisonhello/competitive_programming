#include<bits/stdc++.h>
using namespace std;

int mr(int l,int r){
    return double(rand())/RAND_MAX*(r-l+1)+l;
}

int main(){
    srand(time(0)+clock());
    int q; cin>>q;
    while(q--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        int x,y;
        do{
            x=mr(a,b); y=mr(c,d);
        }while(x==y);
        cout<<x<<" "<<y<<endl;
    }
}
