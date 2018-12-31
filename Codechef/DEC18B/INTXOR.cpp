#include<bits/stdc++.h>
using namespace std;

int a[50004];

int query(int a,int b,int c){
    printf("1 %d %d %d\n",a,b,c);
    fflush(stdout);
    int x; scanf("%d",&x);
    return x;
}

void query(vector<int> &v){
    if(v.size()==4u){
        int q012=query(v[0],v[1],v[2]);
        int q013=query(v[0],v[1],v[3]);
        int q023=query(v[0],v[2],v[3]);
        int q123=query(v[1],v[2],v[3]);
        int all=q012^q013^q023^q123;
        a[v[0]]=all^q123;
        a[v[1]]=all^q023;
        a[v[2]]=all^q013;
        a[v[3]]=all^q012;
    }
    if(v.size()==5u){
        int q012=query(v[0],v[1],v[2]);
        int q013=query(v[0],v[1],v[3]);
        int q024=query(v[0],v[2],v[4]);
        int q134=query(v[1],v[3],v[4]);
        int q234=query(v[2],v[3],v[4]);
        a[v[0]]=q012^q134^q234;
        a[v[1]]=q013^q024^q234;
        a[v[2]]=q013^q024^q134;
        a[v[3]]=q012^q024^q134;
        a[v[4]]=q012^q013^q234;
    }
    if(v.size()==6u){
int q0=query(v[1],v[3],v[5]);
int q1=query(v[2],v[3],v[4]);
int q2=query(v[0],v[1],v[2]);
int q3=query(v[0],v[3],v[5]);
int q4=query(v[2],v[4],v[5]);
int q5=query(v[0],v[1],v[4]);

a[v[2]]=q0^q2^q3;
a[v[1]]=q0^q1^q4;
a[v[0]]=q1^q3^q4;
a[v[3]]=q1^q2^q5;
a[v[4]]=q0^q3^q5;
a[v[5]]=q2^q4^q5;

    }
    if(v.size()==7u){
int q0=query(v[1],v[3],v[4]);
int q1=query(v[0],v[2],v[6]);
int q2=query(v[0],v[1],v[3]);
int q3=query(v[0],v[2],v[5]);
int q4=query(v[1],v[4],v[6]);
int q5=query(v[4],v[5],v[6]);
int q6=query(v[2],v[3],v[5]);

a[v[4]]=q1^q3^q5;
a[v[0]]=q0^q1^q2^q3^q5;
a[v[1]]=q2^q3^q6;
a[v[2]]=q0^q1^q3^q4^q6;
a[v[3]]=q0^q1^q2^q5^q6;
a[v[6]]=q1^q2^q4^q5^q6;
a[v[5]]=q2^q3^q4^q5^q6;

    }
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        memset(a,0,(n+3)<<2);
        vector<int> v(n);
        iota(v.begin(),v.end(),1);
        while(v.size()>=8){
            vector<int> sm(4);
            for(int z=0;z<4;++z){
                sm[z]=v.back();
                v.pop_back();
            }
            query(sm);
        }
        query(v);
        printf("2");
        for(int i=1;i<=n;++i)printf(" %d",a[i]);
        puts("");
        fflush(stdout);
        int res; scanf("%d",&res);
        if(res==1)continue;
        else exit(0);
    }
}
