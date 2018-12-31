#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0)+clock());
    int ta=rand()%10+10,tb=rand()%10+10;
    int la=rand()%ta,ra=rand()%ta;
    if(la>ra)swap(la,ra);
    int lb=rand()%tb,rb=rand()%tb;
    if(lb>rb)swap(lb,rb);
    cout<<la<<" "<<ra<<" "<<ta<<endl;
    cout<<lb<<" "<<rb<<" "<<tb<<endl;
}
