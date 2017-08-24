#include<bits/stdc++.h>
using namespace std;
string ina,inb;
int a[105],b[105];

bool azero(){
    for(int i=0;i<100;i++){
        if(a[i]){
            return 1;
        }
    }
    return 0;
}

void end(){
    // cout<<"jizz"<<endl;
    if(azero()){
        int i;
        for(i=100;i>=0 && !a[i];i--);
        do{
            cout<<a[i];
            i--;
        }while(i>=0);
        cout<<endl;
    }
    else{
        int i;
        for(i=100;i>=0 && !b[i];i--);
        do{
            cout<<b[i];
            i--;
        }while(i>=0);
        cout<<endl;
    }
}

bool cmp(){
    for(int i=100;i>=0;i--){
        if(a[i] && b[i]){
            return a[i]<b[i];
        }
        if(a[i]){
            return 0;
        }
        if(b[i]){
            return 1;
        }
    }
    return 0;
}

bool isnotzero(){
    cout<<"jizz in is not zero"<<endl;
    bool zeroa=0,zerob=0;
    for(int i=0;i<100;i++){
        if(a[i]!=0){
            zeroa=1;
            cout<<"zeroa=1 at i"<<i<<" val"<<a[i]<<endl;
            break;
        }
    }
    for(int i=0;i<100;i++){
        if(b[i]!=0){
            zerob=1;
            cout<<"zerob=1 at i"<<i<<" val"<<b[i]<<endl;
            break;
        }
    }
    if(zeroa&&zerob){
        cout<<"ret 1"<<endl;
        return 1;
    }
    cout<<"ret 0"<<endl;
    return 0;
}

void sol(){
    while(isnotzero()){
        // cout<<"jizz"<<endl;
        if(cmp()==0){
            //cout<<"jizz2"<<endl;
            //a bigger
            for(int i=0;i<100;i++)cout<<a[i];cout<<endl;
            while(cmp()==0 && isnotzero()){
                cout<<"jizz5"<<endl;
                for(int i=0;i<100;i++){
                    a[i]=a[i]-b[i];
                    if(a[i]<0){
                        a[i]+=10;
                        a[i+1]--;
                    }
                }
            }
        }
        else{
            //cout<<"jizz1"<<endl;
            //b bigger
            for(int i=0;i<100;i++)cout<<b[i];cout<<endl;
            while(cmp()==1 && isnotzero()){
                cout<<"jizz4"<<endl;
                for(int i=0;i<100;i++){
                    b[i]=b[i]-a[i];
                    if(b[i]<0){
                        b[i]+=10;
                        b[i+1]--;
                    }
                }
            }
            //cout<<"jizz3"<<endl;
        }
    }
    //cout<<"jizz"<<endl;
    end();
}

int main(){
    cin>>ina>>inb;
    for(int i=0;i<ina.length();i++){
        a[i]=ina[ina.length()-i-1]-'0';
        //cout<<a[i]<<" "<<endl;
    }
    for(int i=0;i<inb.length();i++){
        b[i]=inb[inb.length()-i-1]-'0';
    }
    sol();
}
