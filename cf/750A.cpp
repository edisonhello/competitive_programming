#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int TL=240-k;
    for(int i=1;i<=n;++i){
        if(TL>=5*i){
            TL-=5*i;
        }
        else{
            cout<<i-1<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
}
