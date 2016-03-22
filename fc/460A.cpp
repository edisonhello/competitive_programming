#include<bits/stdc++.h>
using namespace std;
int main(){
    int left,eve;cin>>left>>eve;int tot=0;

    while(left){
        left--;tot++;
        if(tot%eve==0){
            left++;
        }
    }
    cout<<tot<<endl;

}
