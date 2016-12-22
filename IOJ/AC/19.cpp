#include<cstdio>
#include<map>
using namespace std;
int a[100005],c[100005];
int main(){
  int n,x,ans=0;
  scanf("%d%d",&n,&x);
  for(int i=0;i<n;++i){
    scanf("%d",a+i);
    ++c[a[i]];
  }
  for(int i=0;i<n;++i){
    if((x^a[i])>100000)continue;
    ans+=c[x^a[i]];
  }
  if(x==0)ans-=n;
  printf("%d\n",ans>>1);
}
