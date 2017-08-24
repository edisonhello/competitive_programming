#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
using namespace std;

int main(){
    int n;cin>>n;
    int *a=new int[n];
    int *b=new int[n];

    for(int i=0;i<n;i++){
        int t;cin>>t;
        a[i]=t/2;
        b[i]=(t+1)/2;
    }

    int ans1=0,ans2=0;
    int i,j;
    for(i=0;i<n;i=j){
        int tmp=0;
        for(j=i;a[i]==a[j]&&j<n;j++){
            tmp++;
        }
        ans1 = max(ans1,tmp);
    }
    for(i=0;i<n;i=j){
        int tmp=0;
        for(j=i;b[i]==b[j]&&j<n;j++){
            tmp++;
        }
        ans2 = max(ans2,tmp);
    }
//cout<<ans1<<ans2<<endl;
    int ans = max(ans1,ans2);
    cout<<ans<<endl;
}
