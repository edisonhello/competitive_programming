#include<bits/stdc++.h>
using namespace std;
int n;
bool u[23];

int a[23][23];
void dogcd(int i)
{for(int j = 1; j <= n; ++j)
    u[j] &= a[i][j];
}

int main()
{int ans=0,swp=87878787;
 cin >> n;
 for(int i = 1; i <= n; ++i)
 {string s; cin >> s;
  for(int j = 1; j <= n; ++j)
  {a[i][j]=s[j-1]=='+';
  }
 }
 for(int st = 0; st < (1 << n); ++st)
 {
 vector<int> x,y;
  int cur = st, k = 1, sum = 0, num = 0;
  for (int i = 1; i <= n; ++i) u[i] = true;
  while(cur)
  {if (cur&1)
   {
    dogcd(k);
    x.push_back(k);
    ++sum;
   }
   cur>>=1;
   ++k;
  }
   for(int me = 1; me <= n; ++me) if(u[me]) ++num,y.push_back(me);
   if(ans<=min(sum,num)){
    if(ans<min(sum,num))swp=87878787;
    ans=min(sum,num);
    bool DE=(ans==9)&0;
    int xswp = 8787878, yswp = 7878787;
    int xat[23],yat[23];
    memset(xat,0,sizeof(xat));
    memset(yat,0,sizeof(yat));
    for(int i:x)++xat[i];
    for(int i:y)++yat[i];
    for(int i=1;i<=n;++i){
      xat[i]+=xat[i-1];
      yat[i]+=yat[i-1];
    }
    if(DE){
        for(int i=1;i<=n;++i)cout<<xat[i]<<" ";cout<<endl;
        for(int i=1;i<=n;++i)cout<<yat[i]<<" ";cout<<endl;
    }
    for(int i=1;i<=n-ans+1;++i){
     xswp=min(xswp,ans-xat[i+ans-1]+xat[i-1]);
     yswp=min(yswp,ans-yat[i+ans-1]+yat[i-1]);
     if(DE){
        cout<<i<<":"<<xswp<<", "<<yswp<<endl;
     }
     swp=min(xswp+yswp,swp);
    }
   }
 }
 cout << ans << ',' << swp << endl;

 return 0;
}
