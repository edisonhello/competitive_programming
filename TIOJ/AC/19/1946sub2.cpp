#include<iostream>
#include<cstring>
using namespace std;

int a[10006];
int cho[10006];
int cnt[10006];
int bg[10006];

int get(int n){
    if(!n)return 999999;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;++i)++cnt[cho[i]];
    for(int i=0,j=0;i<1e4;++i){
        while(cnt[i]){cnt[i]--;cho[j++]=i;}
    }
    return cho[((n-1)>>1)];
}

int main(){
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i){
        int pos=0;
        for(int j=0;j<i;++j){
            if(a[j]>a[i]){
                cho[pos++]=a[j];
            }
        }
        int La=get(pos);
        pos=0;
        for(int j=i+1;j<n;++j){
            if(a[j]>a[i]){
                cho[pos++]=a[j];
            }
        }
        int Ra=get(pos);
        int c=min(La,Ra);
        if(c==999999)continue;
        ++bg[c];++bg[i];
    }
    int ans=0;
    for(int i=0;i<n;++i)ans=max(ans,bg[i]);
    cout<<ans<<endl;
}
