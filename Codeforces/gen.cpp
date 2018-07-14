#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
    srand(clock());
    int n=100000,l=3;
    cout<<n<<" "<<l<<endl;
    for(int i=1;i<n;++i)a[i]=rand()%10001;
    for(int i=1;i<n;++i)cout<<a[i]<<" "; cout<<endl;
}
