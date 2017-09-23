#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,m;
    cin>>h>>m;
    m+=150;
    while(m>=60){
        ++h;
        m-=60;
    }
    if(h>=24){
        h-=24;
    }
    printf("%02d:%02d\n",h,m);
}
