#include<bits/stdc++.h>
using namespace std;
#define uomap unordered_map

uomap<int,uomap<int,uomap<int,uomap<int,int>>>> tb;

char cname[1004][22];
string name[1004];

int main(){
    int n,m; scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;++i){
        int a,b,c,d;
        scanf("%s %d.%d.%d.%d\n",cname[i],&a,&b,&c,&d);
        // name[i]=string(cname[i],cname[i]+strlen(cname[i]));
        tb[a][b][c][d]=i;
    }
    for(int i=0;i<m;++i){
        char cmd[22]={0};
        int a,b,c,d;
        scanf("%s %d.%d.%d.%d;\n",cmd,&a,&b,&c,&d);
        printf("%s %d.%d.%d.%d; #%s\n",cmd,a,b,c,d,cname[tb[a][b][c][d]]);
    }
}

