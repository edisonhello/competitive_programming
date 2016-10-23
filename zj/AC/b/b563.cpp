#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> ch[105];
int main(){
    while(cin>>n){
        memset(ch,0,sizeof(ch));
        int c=0;
        for(int i=0;i<n;++i){
            int a,b;cin>>a>>b;
            for(int j=0;j<i;++j){
                if(ch[j]==(pair<int,int>){b,a}){
                    c++;
                    ch[j]={0,0};
                    goto fd;
                }
            }
            ch[i]={a,b};
            fd:;
        }
        cout<<c<<endl;
    }
}
