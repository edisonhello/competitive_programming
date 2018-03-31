#include<bits/stdc++.h>
using namespace std;

int w[5005][5005];

int main(){
    srand(time(0));
    freopen("in.txt","w",stdout);
    int n=1000,k=rand()%1000;
    cout<<n<<" "<<k<<endl;
    for(int i=1;i<=n;++i){
        cout<<abs(rand()*rand())%10000<<" ";
    }
    cout<<endl;
}
