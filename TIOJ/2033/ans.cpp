#include<vector>
#include<cstdio>
#include<bitset>
#include<iostream>
using namespace std;

vector<int> a,b;
int pos[3000006];
bitset<3000006> v;

int main(){
    int x=0;
    char c;
    while((c=getchar_unlocked())!='\n'){
        if(c==' '){
            if(x)a.push_back(x);
            x=0;
        }
        else x=x*10+c-'0';
    }
    if(x)a.push_back(x),x=0;
    while((c=getchar_unlocked())!='\n'){
        if(c==' '){
            if(x)b.push_back(x);
            x=0;
        }
        else x=x*10+c-'0';
    }
    if(x)b.push_back(x);
    if(a.size()!=b.size())return printf("-1\n"),0;
    for(int i=0;i<a.size();++i)pos[a[i]]=i;
    for(int i=0;i<b.size();++i)b[i]=pos[b[i]];
    int ans=0,cnt;
    for(int i=0;i<b.size();++i){
        if(v[i])continue;
        if(b[i]==i)continue;
        register int j=b[i]; cnt=1;
        v[i]=1;
        while(b[j]!=i)v[j]=1,j=b[j],++cnt;
        v[j]=1;
        ans+=cnt;
    }
    printf("%d\n",ans);
}
