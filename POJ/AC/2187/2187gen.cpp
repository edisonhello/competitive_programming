#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    freopen("in","w",stdout);
    srand(time(NULL));
    int N=rand()%9+12;
    cout<<N<<endl;
    while(N--){cout<<rand()%100+1<<" "<<rand()%100+1<<endl;}
}
