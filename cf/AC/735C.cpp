#include<iostream>
using namespace std;
int main(){
    long long n;
    long long F[5555];
    cin>>n;
    int ptr=1;
    F[1]=2,F[2]=3;
    while(F[ptr]<=n){
        ++ptr;
        if(ptr>2){
            F[ptr]=F[ptr-1]+F[ptr-2];
        }
    }
    cout<<ptr-1<<endl;
}
