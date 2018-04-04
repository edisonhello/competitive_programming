#include<bits/stdc++.h>
using namespace std;

int k,tk[22];
bitset<100000008> sg,v;

void go(int n){
    if(v[n])return;
    v[n]=1;
    for(int i=0;i<k;++i){
        if(tk[i]<=n){
            go(n-tk[i]);
            if(sg[n-tk[i]]==0){
                sg[n]=1;
                break;
            }
        }
    }
}

int main(){
    long long n; cin>>n>>k;
    for(int i=0;i<k;++i)cin>>tk[i];
    if(n<=100000000){
        sort(tk,tk+k);
        for(int i=1;i<=n;++i){
            for(int j=0;j<k;++j){
                if(tk[j]<=i){
                    if(!sg[i-tk[j]]){
                        sg[i]=1;
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        cout<<sg.count()<<endl;

        // for(int i=1;i<=300;++i)cout<<sg[i]; cout<<endl;
    }
    else{
        for(int i=1;i<=100000;++i)go(i);
        int front10000=0;
        for(int i=1;i<=10000;++i)if(sg[i])++front10000;
        /* for(int i=1;i<=11000;++i){
            cout<<sg[i];
            if((i-10000)%10000==0)cout<<endl;
        } */
        int loop=1;
        for(;;++loop){
            bool ok=1;
            for(int i=10001;i+loop<=100000;++i){
                if(sg[i]!=sg[i+loop]){
                    ok=0;
                    break;
                }
            }
            if(ok)break;
        }
        // cout<<"loop: "<<loop<<endl;
        int inloop=0,outloop=0,c_out=(n-10000)%loop;
        for(int i=1;i<=loop;++i)if(sg[10000+i])++inloop;
        for(int i=1;i<=c_out;++i)if(sg[10000+i])++outloop;
        // cout<<inloop<<" "<<outloop<<" "<<c_out<<endl;
        cout<<front10000+1ll*inloop*((n-10000)/loop)+outloop<<endl;
    }
}
