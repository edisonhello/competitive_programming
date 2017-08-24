#include<bits/stdc++.h>
#define mid (l+r)/2
using namespace std;

int n,*ant,*cnt;

void go(int q,int l,int r){    // printf("go %d\n",q);
    if(l==r){
        cout<<l+1<<endl;
        return;
    }
    if(cnt[(l+r)/2]>q){     //printf("jizz\n");
        go(q,l,mid);
        return;
    }
    if(cnt[(l+r)/2+1]<=q){
        go(q,mid+1,r);
        return;
    }
    cout<<(l+r)/2+2<<endl;
    return;
}




int main(){
    cin>>n;
    ant=new int[n];
    cnt=new int[n];
    for(int i=0;i<n;i++){
        cin>>ant[i];
        if(i)cnt[i]=ant[i]+cnt[i-1];
        else cnt[i]=ant[i]+1;
            //printf("%d:%d,%d\n",i,ant[i],cnt[i]);
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int q;cin>>q;
        go(q,0,n-1);
    }
}
