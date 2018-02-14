#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,k; cin>>x>>y>>k;
    int g=__gcd(x,y);
    if(k%g){cout<<"0"<<endl; return 0;}
    if(k>x && k>y){cout<<"0\n"; return 0;}
    int xx=0,yy=0;
    while(xx!=k && yy!=k){
        if(xx==0){
            cout<<"1 1\n";
            xx=x;
        }
        else{
            if(yy<y){
                cout<<"3 1 2"<<endl;
                int ept=y-yy;
                if(xx>ept){
                    xx-=ept;
                    yy=y;
                }
                else{
                    yy+=xx;
                    xx=0;
                }
            }
            else{
                cout<<"2 2"<<endl;
                yy=0;
            }
        }
    }
    cout<<0<<endl;
}
