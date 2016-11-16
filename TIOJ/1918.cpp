#include<iostream>
using namespace std;
#define ull unsigned long long
#define ll long long
ll x[100005],y[100005],z[100005];ull nr;
int n;
inline ull d(int i,int j){
    return (ull)((x[i]-x[j])*(x[i]-x[j]))+(ull)((y[i]-y[j])*(y[i]-y[j]))+(ull)((z[i]-z[j])*(z[i]-z[j]));
}
int main(){
    cin>>n;
    nr=-1;
    for(int i=0;i<n;++i){
        cin>>x[i]>>y[i]>>z[i];
        for(int j=0;j<i;++j){
            nr=min(nr,d(i,j));
        }
    }
    cout<<nr<<endl;
}
