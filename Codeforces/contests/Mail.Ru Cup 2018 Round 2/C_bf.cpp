#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll la,ra,ta,lb,rb,tb; cin>>la>>ra>>ta>>lb>>rb>>tb;
    ll mx=0;
    int cnt=100000;
    while(cnt--){
        mx=max(mx,min(ra,rb)-max(la,lb)+1);
        if(la<lb)la+=ta,ra+=ta;
        else lb+=tb,rb+=tb;
    }
    cout<<mx<<endl;
}
