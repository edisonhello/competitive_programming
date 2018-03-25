#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    int cnt2=n/2;
    int cnt=cnt2+(n&1);
    int a=0;
    do{
        if(cnt%m==0){
            cout<<cnt<<endl;
            exit(0);
        }
        ++cnt;--cnt2;
    }while(cnt2>=0);
    cout<<-1<<endl;
}
