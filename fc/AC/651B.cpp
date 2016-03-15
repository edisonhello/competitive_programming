#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<int> bt;
    for(int i=0;i<n;i++){
        int t;scanf("%d",&t);bt.push_back(t);
    }
    sort(bt.begin(),bt.end());
    int tmax=1,fmax=1,tmp = bt[0];
    for(int i=1;i<n;i++){
        if(bt[i] == tmp){
            tmax++;
            if(tmax>fmax){
                fmax = tmax;
            }
        }
        else{
            tmp = bt[i];
            tmax = 1;
        }
    }
    printf("%d",n-fmax);
}
