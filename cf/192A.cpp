#include<bits/stdc++.h>

using namespace std;
const int mx = 44730;
unsigned int tri[mx];



void mkfm(){
    for(int i=1;i<=44730;i++){
        tri[i-1] = i*(i+1)/2;
    }return ;
}

bool _(int a){
    int i;
    for(i=44729;i>=0;i--){
        if(tri[i]<a){
            break;
        }
    }int jizz=i;
    for(;i>=jizz/2;i--){
        for(int j=0;tri[i]+tri[j]<=a;j++){
            if(tri[i]+tri[j]==a){
                return 1;
            }
        }
    }return 0;
}

int main(){
    long long a;cin>>a;
    mkfm();
    if(_(a)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


}
