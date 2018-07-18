#include<bits/stdc++.h>
using namespace std;


int main(){
    int k; cin>>k;
    for(int i=19;;++i){
        int sum=0;
        int j=i;
        while(j)sum+=j%10,j/=10;
        if(sum==10)--k;
        if(k==0)exit((cout<<i<<endl,0));
    }
}
