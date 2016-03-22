#include<bits/stdc++.h>
using namespace std;
int b,t,*a;
bool *c;
int main(){
    cin>>b>>t;
    a = new int[b];
    for(int i=0;i<b;i++){
        cin>>a[i];
    }
    c = new bool[b];
    memset(c,1,sizeof(c));

    int i,j=0,mx=0,now=0;
    for(i=0,j=0;i<b;i++){
        for(;j<b;j++){
            if(c[j])now+=a[j];
            c[j]=0;
            if(now>t){  //cout<<"i"<<i<<" j"<<j<<"jizz now"<<now<<endl;
                break;
            }

            mx=max(mx,j-i+1);   //cout<<"i"<<i<<" j"<<j<<" now"<<now<<endl;
        }
        now-=a[i];  //cout<<"--- a[i]"<<a[i]<<"now now"<<now<<endl;
    }
    cout<<mx<<endl;
}
