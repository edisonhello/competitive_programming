#include<iostream>
using namespace std;
int djs[200005],cnt[200005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);djs[x]=y;}


int main(){
  int n;cin>>n;
  for(int i=1;i<=n;++i)djs[i]=i;
  for(int i=1,d;i<=n;++i){
    cin>>d;U(i,d);
  }
  int c1=0;
  for(int i=1,r;i<=n;++i){
    cin>>r;if(r)++c1;
  }
  int gps=0;
  for(int i=1;i<=n;++i)++cnt[F(i)];
  for(int i=1;i<=n;++i)if(cnt[i])++gps;
  cout<<(gps==1?0:(gps))+(!(c1&1))<<endl;
}
