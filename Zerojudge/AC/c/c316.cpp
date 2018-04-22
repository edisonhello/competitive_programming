#include<bits/stdc++.h>
using namespace std;

int x[1004],y[1004];

#define q(x) ((x)*(x))
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>x[i]>>y[i];
    int i1,i2,d=1;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            tie(d,i1,i2)=min(make_tuple(d,i1,i2),make_tuple(-q(x[i]-x[j])-q(y[i]-y[j]),i,j));
        }
    }
    cout<<i1<<" "<<i2<<endl;
}
