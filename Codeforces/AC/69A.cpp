#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y,z;
    cin>>n;
    x=y=z=0;
    for(int i=0;i<n;i++){
        int xi,yi,zi;
        cin>>xi>>yi>>zi;
        x+=xi;
        y+=yi;
        z+=zi;
    }
    if(!x && !y && !z){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
