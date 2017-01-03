#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
  int T=1;
  // scanf("%d",&T);
  while(T--) {
    LL a,b;
    scanf("%lld%lld",&a,&b);
    if(a<=1 || b==0) {
      puts("-1");
      continue;
    }
    int ans=0;
    LL c = 1;
    while(c<=b) {c*=a; ans++;}
    printf("%d\n",ans-1);
  }
}

/*
#include<cstdio>
int main(){
    puts("1\n999999999999999999 1000000000000000000");
    return 0;
}
*/
