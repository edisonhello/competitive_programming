#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,w;cin>>c>>w;
    int cnt=0;
    while(c<12){
        --w;++c;
    }
    while(c>=12&&w>0){
        cnt++;c-=10;w--;
        while(c<12){
            --w;++c;
        }
    }
    cout<<cnt<<endl;
}
