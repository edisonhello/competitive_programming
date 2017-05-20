#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int _X=(1<<3);
int _A[_X];
bool fake;

void Init(){
    fake=0;
    srand(7122);
    cout<<"gen : ";
    for(int i=0;i<_X;++i){
        _A[i]=rand()&1;
        cout<<_A[i]<<" ";
    }
    cout<<endl;
    // for(int i=0;i<_X;++i)cout<<_A[i];cout<<endl;
    return;
}
int Query(int n, int a[]){
    int rt=0;
    cout<<"query for ";
    for(int i=0;i<n;++i){
        cout<<a[i]<<"("<<_A[a[i]]<<") ";
        rt+=_A[a[i]];
    }
    cout<<", ans: "<<(rt&1);
    if(!fake && rand()&1111){
        fake=1;
        ++rt;
        cout<<" fake!";
    }
    cout<<endl;
    return rt&1;
}
bool Give(bool a[]){
    for(int i=0;i<_X;++i){
        if(a[i]!=_A[i])return 1;
    }
    return 0;
}
