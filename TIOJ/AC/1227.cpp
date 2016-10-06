#include "lib1227.h"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define X first
#define Y second
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define m (l+r)/2

int n;
ll *d,chg[1000002],ging;
bool firstQuery;

void init(int N, long long D[]){
    n=N;
    d=D;
}
void change(int a, int b, long long k){
    if(a&1){
        chg[a]+=-k;
        chg[b+1]+=k;
    }
    else{
        chg[a]+=k;
        chg[b+1]+=-k;
    }
}
long long query(int c){
    if(!firstQuery){
        firstQuery=1;
        for(int i=0;i<n;i++){
            ging+=chg[i];
            // cout<<ging<<" ";
            if(i&1){
                d[i]+=ging;
            }
            else{
                d[i]-=ging;
            }
        }
        // cout<<endl;
    }
    return d[c];
}
