#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    int n5l = n%5;
    int m5l = m%5;
    int n5  = n/5;
    int m5  = m/5;

    int n5t[5]={0,0,0,0,0};
    int m5t[5]={0,0,0,0,0};

    n5t[0]=n5t[1]=n5t[2]=n5t[3]=n5t[4]=n5;
    if(n5l==1){
        n5t[1]++;
    }
    if(n5l==2){
        n5t[1]++;
        n5t[2]++;
    }
    if(n5l==3){
        n5t[1]++;
        n5t[2]++;
        n5t[3]++;
    }
    if(n5l==4){
        n5t[1]++;
        n5t[2]++;
        n5t[3]++;
        n5t[4]++;
    }

    // for(int i=0;i<5;i++)cout<<n5t[i];cout<<endl;

    m5t[0]=m5t[1]=m5t[2]=m5t[3]=m5t[4]=m5;
    if(m5l==1){
        m5t[1]++;
    }
    if(m5l==2){
        m5t[1]++;
        m5t[2]++;
    }
    if(m5l==3){
        m5t[1]++;
        m5t[2]++;
        m5t[3]++;
    }
    if(m5l==4){
        m5t[1]++;
        m5t[2]++;
        m5t[3]++;
        m5t[4]++;
    }

    // for(int i=0;i<5;i++)cout<<m5t[i];cout<<endl;

    unsigned long long ans=0;
    ans+=(unsigned long long)((unsigned long long)n5t[0]*(unsigned long long)m5t[0]);
    for(int i=1;i<5;i++){
        ans+=(unsigned long long)((unsigned long long)n5t[i]*(unsigned long long)m5t[5-i]);
    }
    cout<<ans<<endl;
}
