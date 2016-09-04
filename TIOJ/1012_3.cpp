#include<stdio.h>
#define g getchar_unlocked()
#define p putchar_unlocked
char n,m,i,j,c[8];
bool a[8],y;
int main(){
n=g-'0';g;
m=g-'0';g;
for(i=0;i<n;++i){
c[i]=g-'0';g;
a[c[i]]=1;
y=0;
if(c[i]==n||!a[c[i]+1]){
y=1;
}
else{
for(j=1;j<=m+1;j++){
if(i-j>=0){
if(c[i-j]==c[i]+1){
y=1;
break;
}}
else{
y=1;
break;
}}}
if(!y){
p('n');
p('o');
p('\n');
return 0;
}}
p('y');
p('e');
p('s');
p('\n');
}
