#include<bits/stdc++.h>
using namespace std;

int main(){
    int sk,lv; while(cin>>sk>>lv){
        if(sk==0){cout<<0<<endl; continue;}
        lv=min(lv,200);

        int pt=1+max(0,(lv-(sk==2?8:10)))*3;
        if(lv>=30)++pt;
        if(lv>=70)++pt;
        if(lv>=120)pt+=3;
        cout<<pt<<endl;
    }
}
