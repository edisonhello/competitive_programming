#include<bits/stdc++.h>
using namespace std;

int main(){
    int nt=0,n; cin>>n; while(n--){
        int s,d; cin>>s>>d;
        if(nt<s)nt=s;
        else{
            nt=((nt-s)/d+1)*d+s;
        }
    }
    cout<<nt<<endl;
}
