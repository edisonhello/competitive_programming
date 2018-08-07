#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    srand(clock());
    int r=10,c=10,n=50;
    cout<<r<<" "<<c<<" "<<n<<endl;
    while(n--){
        int cmd=rand()%25;
        if(cmd){
            cout<<1<<" "<<rand()%r<<" "<<rand()%c<<" "<<rand()%100<<endl;
        }
        else{
            int x1=rand()%r,y1=rand()%r;
            int x2=rand()%(r-x1+1)+x1,y2=rand()%(c-y1+1)+y1;
            cout<<2<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        }
    }

}
