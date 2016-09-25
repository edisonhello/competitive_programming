#include<algorithm>
#include<iostream>
using namespace std;
int n,p,y,mx,mn,s;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    while(n--){
        cin>>p>>y;
        mx=(1<<29);
        mn=-(1<<29);
        p--;
        while(p--){
            cin>>s;
            if(s<mx && y<s) mx=s;
            if(s>mn && y>s) mn=s;
        }
        cout<<mx<<" "<<mn<<'\n';
    }
}
