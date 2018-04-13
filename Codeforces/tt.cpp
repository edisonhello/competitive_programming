#include<bits/stdc++.h>
using namespace std;


#define ull unsigned long long

int get_max(int* a,int l){
    int mx=0,i;
    for(i=0;i<l;i++){
        if(a[i]>mx)mx=a[i];
    }
    return mx;
}

int a[10000007];
int main(){
    srand(time(0));
    for(int i=0;i<10000000;++i)a[i]=rand();
    ull t=clock();
    int ans=get_max(a,10000000);
    ull t2=clock();
    cout<<t2-t<<" "<<ans<<endl;
}
