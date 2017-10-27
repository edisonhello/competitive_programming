#include<bits/stdc++.h>
using namespace std;
int main(){
    double d,l,pi=acos(-1);
    while(cin>>d>>l){
        printf("%.3lf\n",pi*(l/2)*sqrt(l*l/4-(d/2)*(d/2)));
    }
}
