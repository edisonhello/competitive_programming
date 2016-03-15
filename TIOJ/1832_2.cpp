#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long

ull *m;
ull *fx;

int main(){
    int n,q;scanf("%d %d",&n,&q);

    m = new ull[n];
    fx= new ull[n];
    for(int i=0;i<n;i++){scanf("%llu",&m[i]);
        if(i!=0)fx[i] = m[i] ^ fx[i-1];
        else{fx[i] = m[i];}
    }

    for(int i=0;i<q;i++){
        int l,r;scanf("%d %d",&l,&r);
        if(l!=1)printf("%llu\n",fx[l-2]^fx[r-1]);
        else{printf("%llu\n",fx[r-1]);}
    }

}
