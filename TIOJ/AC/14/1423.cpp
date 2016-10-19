#include<bits/stdc++.h>
using namespace std;
#define ld long double
int n;
ld x[400],y[400];
ld cross(int a,int b,int c){
    // cout<<"cross "<<a<<" "<<b<<" "<<c<<endl;
    return (x[b]-x[a])*(y[c]-y[a])-(x[c]-x[a])*(y[b]-y[a]);
}
int pn[2];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x[i]>>y[i];
    }
    int cnt=0;
    for(int a=0;a<n;++a){
        for(int b=a+1;b<n;++b){
            if(x[a]==x[b]&&y[a]==y[b])continue;
            pn[0]=pn[1]=0;
            for(int c=0;c<n;++c){
                if(c==a||c==b)continue;
                ld res=cross(a,b,c);
                if(abs(res-0.0)>0.0001 && res>0.0){
                    // cout<<"pn0++"<<endl;
                    ++pn[0];
                }
                else if(abs(res-0.0)>0.0001 && res<0.0){
                    // cout<<"pn1++"<<endl;
                    ++pn[1];
                }
            }
            cnt+=pn[0]*pn[1];
        }
    }
    cout<<cnt<<'\n';
}
