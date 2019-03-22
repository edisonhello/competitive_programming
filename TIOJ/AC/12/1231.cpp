#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

struct food{int c,t;};
bool cmp_c(const food &a,const food &b){return a.c<b.c;}
bool cmp_t(const food &a,const food &b){return a.t<b.t;}

#define PQ priority_queue
PQ<food,vector<food>,decltype(&cmp_c)> pqc(cmp_c);
PQ<food,vector<food>,decltype(&cmp_t)> pqt(cmp_t);

int main(){
 int n,t,ans=0;scanf("%d",&n);
 for(int i=0,iu,iv;i<n;++i){
  scanf("%d%d",&iu,&iv);
  pqt.push({iu,iv});
 }
 scanf("%d",&t);
 for(int nt=t;t;--t){
  while(pqt.size() && pqt.top().t>=t){pqc.push(pqt.top());pqt.pop();}
  if(pqc.empty())--ans;
  else{ans+=pqc.top().c;pqc.pop();}
  
 }
 printf("%d\n",max(0,ans));
}
