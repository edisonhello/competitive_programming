#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int m,n;
    while(cin>>m>>n){
        if(m==0 && n==0)break;
        ll tm=0;
        int wr[120]={0};
        int sol=0;
        bool gt[120]={0};
        while(n--){
            ll t;
            int w,g;
            cin>>t>>w>>g;
            if(gt[w])continue;
            if(g==0){
                wr[w]++;
            }
            else{
                tm+=t+wr[w]*20;
                sol++;
                gt[w]=1;
            }
        }
        cout<<tm<<' '<<sol<<'\n';

    }
}
