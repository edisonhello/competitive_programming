#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    if(n%10==5)n+=5;
    else if(n%10==0);
    else if(n%10<5)n-=n%10;
    else n=n-n%10+10;
    cout<<n<<endl;
}
