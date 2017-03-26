#include<iostream>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int n,a[105][105],d[105][105];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            cin>>a[i][j];
        }
    }
    for(int i=n;i>0;--i){
        for(int j=1;j<=i;++j){
            d[i][j]=a[i][j]+max(d[i+1][j],d[i+1][j+1]);
        }
    }
    cout<<d[1][1]<<endl;
}
