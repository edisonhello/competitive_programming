#include<iostream>
#include<map>
using namespace std;

int djs[400055];
int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);djs[x]=y;}
bool C(int x,int y){return F(x)==F(y);}

int main(){
    int n>>m>>q;cin>>n>>m>>q;
    string s;
}
