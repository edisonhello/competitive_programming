#include<iostream>
#define ld long double
using namespace std;
#include<cmath>
#include<stdio.h>

int main(){
    freopen("progress_pie.txt","r",stdin);
    freopen("progress_pie.out","w",stdout);
    int ts;cin>>ts;
    for(int c=1;c<=ts;++c){
        cout<<"Case #"<<c<<": ";
        ld p,x,y;
        cin>>p>>x>>y;
        if((50-x)*(50-x)+(50-y)*(50-y)>(ld)2500)cout<<"white\n";
        else{
            ld ang=atan2(50-x,y-50);
            // cout<<-(ang/acos(-1)*50)<<endl;
            if(-(ang/acos(-1)*50)<p)cout<<"black\n";
            else cout<<"white\n";
        }
    }
}
