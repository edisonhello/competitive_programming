
#include<bits/stdc++.h>
using namespace std;



#define ull unsigned long long

int *a;
int cnt;
int main(){
    ios_base::sync_with_stdio(0);
cnt=0;
    int n;
    scanf("%d",&n);
    a = new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int q;cin>>q;
    for(int i=0;i<q;i++){
        int com;cin>>com;
        if(com == 1){
            int l,r;cin>>l>>r;
            int tot=0;
            for(int i=l-1;i<=r-1;i++)
            {
                tot+=a[i];
            }
            cout<<tot<<endl;
        }
        if(com == 2){
    //cout<<"got com2 ";
            int tl,tr,tx;cin>>tl>>tr>>tx;
    //cout<<tl<<" to "<<tr<<" wth "<<tx<<endl;
            for(int i=tl-1;i<=tr-1;i++){
                a[i] = a[i]^tx;
            }

        }
    }
}
