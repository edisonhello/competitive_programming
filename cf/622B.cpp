#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
using namespace std;

int main(){
    string a;cin>>a;
    string m,h;
    m=a;h=a;
    m.assign(m,0,2);
    h.assign(h,3,2);
    //cout<<m<<" "<<h;
    stringstream ss,sss;
    ss<<h;
    int mn;ss>>mn;
    sss<<m;
    int hr;sss>>hr;
    //cout<<hr<<" "<<mn;
    int ad;cin>>ad;
    mn+=ad%60;
    hr+=ad/60;
    hr+=mn/60;
    mn =mn%60;
    hr =hr%24;
    
    //cout<<hr<<":"<<mn<<endl;
    printf("%02d:%02d\n",hr,mn);
}
