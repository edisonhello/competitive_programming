#include<bits/stdc++.h>
using namespace std;

bitset<111> v;
int to[111],front,back;
long long a[111];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    v[0]=1;
    for(;;){
        bool no=1;
        for(int i=0;i<n;++i){
            if((a[i]==a[back]/3 && a[back]%3==0) || a[i]==a[back]*2){
                no=0;
                to[back]=i;
                back=i;
                break;
            }
        }
        if(no)break;
    }
    for(;;){
        bool no=1;
        for(int i=0;i<n;++i){
            if((a[i]%3==0 && a[i]/3==a[front]) || a[front]==a[i]*2){
                no=0;
                to[i]=front;
                front=i;
                break;
            }
        }
        if(no)break;
    }
    while(front!=back){
        cout<<a[front]<<" ";
        front=to[front];
    }
    cout<<a[front]<<endl;
}
