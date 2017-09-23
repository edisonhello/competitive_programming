#include<cmath>
#include<iostream>
#define ll long long
#define ld long double
using namespace std;

struct p{
    int x,y;
} a[4];
ld d1,d2;
ld gdg(p &a,p &b){

}

int main(){
    cin>>a[0].x>>a[0].y>>a[1].x>>a[1].y>>a[2].x>>a[2].y;
    d1=(ld)sqrt((ld)(a[0].x-a[1].x)*(ld)(a[0].x-a[1].x)+(ld)(a[0].y-a[1].y)*(ld)(a[0].y-a[1].y));
    d2=(ld)sqrt((ld)(a[1].x-a[2].x)*(ld)(a[1].x-a[2].x)+(ld)(a[1].y-a[2].y)*(ld)(a[1].y-a[2].y));
    //cout<<d1<<endl<<d2<<endl;
    if(d1==d2){
        cout<<a[2].x-(a[1].x-a[0].x)<<" "<<a[2].y-(a[1].y-a[0].y)<<endl;
    }
    if(d1 >d2){
        swap(a[1],a[2]);
        cout<<a[2].x-(a[1].x-a[0].x)<<" "<<a[2].y-(a[1].y-a[0].y)<<endl;
    }
    if(d1 <d2){
        swap(a[0],a[1]);
        cout<<a[2].x-(a[1].x-a[0].x)<<" "<<a[2].y-(a[1].y-a[0].y)<<endl;
    }
}
