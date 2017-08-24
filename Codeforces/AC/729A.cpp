#include<iostream>
using namespace std;

int main(){
    int n;string s;
    cin>>n>>s;
    for(int i=0,j;i<n;++i){
        for(j=i;j<n;++j){
            if(  (j-i)&1  && s[j]=='g')continue;
            if(!((j-i)&1) && s[j]=='o')continue;
            break;
        }
        // cout<<i<<" "<<j<<endl;
        if(s[j-1]=='g')--j;
        if(j-i<=1){cout<<s[i];continue;}
        cout<<"***";
        i=j-1;
    }
    cout<<endl;
}
