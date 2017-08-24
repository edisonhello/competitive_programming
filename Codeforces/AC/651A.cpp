#include<bits/stdc++.h>

using namespace std;

inline int rit(){
    int a;
    scanf("%d",&a);
    return a;
}

int main(){
    int a=rit(),b=rit();
    int cnt=0;
    while(a>1||b>1&&(a>0&&b>0)){
        cnt++;
        int mx,mn;
        mx = max(a,b);
        mn = min(a,b);
        mx -=2;
        mn +=1;
        a = mx;
        b = mn;
    }
    printf("%d\n",cnt);
}
