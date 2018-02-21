#include<bits/stdc++.h>
using namespace std;

int a[100005],n;
int nowstarttime,L,R,cnt;

void rangeinit(int s,int t){
    for(int i=1;i<=t-s;++i){
        cnt+=a[i];
    }
    L=1,R=t-s;
    nowstarttime=s;
}
void timego(){
    cnt-=a[L]; ++L; if(L>n)L=1;
    ++R; if(R>n)R=1; cnt+=a[R];
    --nowstarttime; if(nowstarttime<1)nowstarttime=n;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    int s,t; cin>>s>>t;
    rangeinit(s,t);
    int parti=cnt,besttime=nowstarttime;
    for(int i=0;i<n;++i){
        timego();
        if(cnt>parti || (cnt==parti && nowstarttime<besttime)){
            parti=cnt;
            besttime=nowstarttime;
        }
    }
    cout<<besttime<<endl;
}
