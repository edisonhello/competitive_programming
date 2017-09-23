#include<bits/stdc++.h>
using namespace std;
int main(){
    double a,b,c;
    while(cin>>a>>b>>c){
        double d = b*b-4*a*c;
        if(d>0){
            d = sqrt(d);
            // cout<<d<<endl;
            double ans1,ans2;
            ans1 = (-b+d)/(a*2);
            ans2 = (-b-d)/(a*2);
            cout<<"Two different roots x1="<<(int)(ans1)<<" , x2="<<(int)(ans2)<<endl;
            continue;
        }
        if(d==0){
            d = sqrt(d);
            double ans;
            ans = (-b)/(2*a);
            cout<<"Two same roots x="<<(int)(ans)<<endl;
            continue;
        }
        cout<<"No real root"<<endl;
    }
}
