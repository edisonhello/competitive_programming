#include<cstdio>
using namespace std;
int n,a;char s[7];
int main(){scanf("%d",&n);
while(n--){
scanf("%s",s);
if(s[2]==s[3]&&s[3]==s[4]&&s[4]==s[5])a+=2000;
else if((s[2]==s[3]&&s[3]==s[4])||(s[3]==s[4]&&s[4]==s[5]))a+=1000;
else if(s[2]==s[3]&&s[4]==s[5])a+=1500;}
printf("%d\n",a);}
