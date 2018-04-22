#include<bits/stdc++.h>
using namespace std;

#define oe(x,y) cout<<x<<" "<<y<<'\n'

void do2(int n){
    cout<<n-1<<endl;
    for(int i=2;i<=n;++i)oe(i-1,i);
}

void do3(int n){
    cout<<n-1<<endl;
    oe(1,2);
    oe(2,3);
    oe(3,4);
    for(int i=5;i<=n;++i)oe(i,3);
}

int main(){
    int n,k; cin>>n>>k;
    if(n==2 && k==1){
        cout<<-1<<endl;
    }
    else if(k>=n){
        cout<<-1<<endl;
    }
    else if(k==1){
        cout<<-1<<endl;
    }
    else if(n==3){
        cout<<-1<<endl;
    }
    else if(n==4){
        if(k==2){
            cout<<-1<<endl;
        }
        else if(k==3){
            cout<<3<<endl;
            cout<<1<<" "<<2<<endl;
            cout<<3<<" "<<2<<endl;
            cout<<3<<" "<<4<<endl;
        }
    }
    else if(k==2)do2(n);
    else if(k==3)do3(n);
    else cout<<-1<<endl;
}
