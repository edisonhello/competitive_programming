#include<iostream>
using namespace std;
int n,a,i,c;
string m[14];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    m[0]="1";
    m[1]="1";
    m[2]="2";
    m[3]="6";
    m[4]="24";
    m[5]="120";
    m[6]="720";
    m[7]="5040";
    m[8]="40320";
    m[9]="362880";
    m[10]="3628800";
    m[11]="39916800";
    m[12]="479001600";
    m[13]="6227020800";
    for(c=1;c<=n;c++){
        cin>>a;
        cout<<"Case #"<<c<<":\n";
        for(i=0;i<=a;i++){
            cout<<"TFCIS"<<i<<"="<<m[i]<<"\n";
        }
    }
}
