#include<bits/stdc++.h>
using namespace std;

int a[11111];

int main(){
    srand(clock());
    int n=12;
    for(int i=0;i<n;++i)a[i]=i;
    do{
        bool ok=1;
        random_shuffle(a,a+n);
        for(int i=0;i<n;++i)if(a[i]==0)break;else if(a[i]==n-1)ok=0;
        if(ok)break;
    }while(1);
    cout<<n<<endl;
    for(int i=0;i<n;++i)cout<<a[i]<<" "; cout<<endl;
}
