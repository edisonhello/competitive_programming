#include<cstdio>
#include<algorithm>
#define F for(i=0;i<n;i++)
#define G getchar_unlocked()
#define P putchar_unlocked
int n,i,a[200],t,k;char c;
inline int rit(){t=0,k=1;
do{c=G;if(c=='-')k=-1;}while(c<'0'||c>'9');
do{t=t*10+c-'0';c=G;}while(c>='0'&&c<='9');
return t*k;
}

int main(){while(scanf("%d",&n)!=EOF){
F{a[i]=rit();}
std::sort(a,a+n);
F{if(i)P(' ');printf("%d",a[i]);}P('\n');
}}
