#include<bits/stdc++.h>
using namespace std;

int a[1223];
bitset<1023> v;

int main(){
    int n,m,c; cin>>n>>m>>c;
    srand(time(0));
    while(cin>>m){
        int pos;
        if(m<=c/2){
            pos=1;
            while(1){
                if(!a[pos])break;
                if(a[pos]>m)break;
            ++pos;
            }
        }
        else{
            pos=n;
            while(1){
                if(!a[pos])break;
                if(a[pos]<m)break;
            --pos;
            }
        }
        a[pos]=m;
        cout<<pos<<endl;
        bool unfill=0;
        for(int i=1;i<=n;++i)if(!a[i])unfill=1;
        if(!unfill)break;
    }
}
