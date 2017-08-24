#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
using namespace std;

int main(){
    int n;cin>>n;
    int ary[1005];
    memset(ary,0,sizeof(ary));
    cout<<1<<endl;
    for(int i=0;i<n;i++){
        cin>>ary[i];
    }
    int insthis;
    if(ary[0]!=1){
        cout<<"1 ";
        for(int i=0;i<n;i++){
            if(i)cout<<" ";
            cout<<ary[i];
        }
        cout<<endl;
    }
    else{
        int now=ary[n-1]+1;
        while(1){
            bool fd=0;
            for(int i=0;i<n;i++){
                if(fd%ary[i]==0){
                    fd=1;
                    break;
                }
            }
            if(!fd){
                insthis=now;
            }
            else{
                now++;
            }
        }
        for(int i=0;i<n;i++){
            if(i)cout<<" ";
            cout<<ary[i];
        }
        cout<<" "<<insthis<<endl;
    }
}
