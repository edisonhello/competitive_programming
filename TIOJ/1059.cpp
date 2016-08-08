#include<bits/stdc++.h>
using namespace std;



int main()
{
    int s;cin>>s;
    int t;cin>>t;
    int n;cin>>n;
    int tot=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        tot+=tmp;
    }
    int p20=(((long double)s*0.7)+0.5);
    int p40=(((long double)s*0.8)+0.5);
    int p60=(((long double)s*0.9)+0.5);
    int c20=(((long double)t*0.2)+0.5);
    int c40=(((long double)t*0.4)-c20+0.5);
    int c60=(((long double)t*0.6)-c20-c40+0.5);
cout<<c20<<" "<<c40<<" "<<c60<<endl;
    int pay=((s*(long double)t*0.3)+0.5);

    int get=p20*c20+p40*c40+p60*c60+s*(t-c20-c40-c60);
    cout<<get-pay<<endl;
}
