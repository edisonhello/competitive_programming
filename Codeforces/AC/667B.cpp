#include<bits/stdc++.h>
using namespace std;
int n,row[100005];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>row[i];
    }
    int l=0,r=n-1;
    int lt=0,rt=0;
    sort(row,row+n);
    while(l<=r){
        if(lt<rt){
            lt+=row[l];
            l++;
        }
        else{
            rt+=row[r];
            r--;
        }
        //cout<<lt<<" "<<l<<" "<<rt<<" "<<r<<endl;
    }
    cout<<max(lt,rt)-min(lt,rt)+1<<endl;
}
