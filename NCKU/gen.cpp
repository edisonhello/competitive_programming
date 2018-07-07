#include<bits/stdc++.h>
using namespace std;

bitset<65536> v;
int a[50005];

int main(){
    int n=50000;
    v[0]=1;
    for(int i=1;i<=n;++i){
        int now=0;
        while(v[now]){
            now=rand()%65536;
        }
        a[i]=now;
        v[now]=1;
    }
    sort(a+1,a+1+n);
    cout<<1<<endl;
    cout<<n<<endl;
    for(int i=1;i<=n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
