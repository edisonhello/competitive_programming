#include<iostream>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
int main(){
    ll n,m,h,a;
    while(cin>>n>>m){
        if(!n||!m){
            cout<<"Go Kevin!!\n";
            continue;
        }
        h=sqrt((ld)(2*n/m));
        h-=300;
        if(h<1)h=1;
        // cout<<h;
        for(;;++h){
            a=(1+1+(h-1)*m)*h/2;
            //cout<<"a = "<<a<<endl;
            if(a>n){
                cout<<"No Stop!!\n";
                break;
            }
            else if(a==n){
                cout<<"Go Kevin!!\n";
                break;
            }
        }
    }
}
