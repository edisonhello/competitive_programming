#include<iostream>
using namespace std;

int main(){
    int m,d;cin>>m>>d;
    --d;
    if(m==2){
        d+=28;
    }
    else if(((m<=7)&&(m&1))||((m>=8)&&(!(m&1)))){
        d+=31;
    }
    else{
        d+=30;
    }
    cout<<(d-1)/7+1<<endl;
}
