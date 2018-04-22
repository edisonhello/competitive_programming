#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    int x=0,y=0;
    while(n--){
        int d,dd; cin>>d>>dd;
        if(d==0)y+=dd;
        else if(d==1)x+=dd;
        else if(d==2)y-=dd;
        else x-=dd;
    }
    cout<<x<<" "<<y<<endl;
}
