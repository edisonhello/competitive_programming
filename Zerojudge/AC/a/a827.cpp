#include<bits/stdc++.h>
using namespace std;

string stat[2];

set<int> kill1,kill2;

#define O(x,y) stat[x][y]=='0'

void meow(){
    int ept0=0,ept1=0;
    for(char j:stat[0])if(j=='0')++ept0;
    for(char j:stat[1])if(j=='0')++ept1;
    if(ept0==0)exit(7122);

    if(ept0==2)for(int i=0;i<7;++i){
        if(O(0,i) && O(0,i+1)){
            kill1.insert(1);
            if(ept1==2)kill2.insert(1);
        }
    }
    
    for(int i=0;i<5;++i){
        if(O(0,i) && O(0,i+1) && O(0,i+2) && O(0,i+3) && ept0==4){
            kill1.insert(2);
        }
        else if(O(1,i) && O(1,i+1) && O(1,i+2) && O(1,i+3) && ept1==4){
            kill1.insert(2);
        }
    }
    if(ept0==1)for(int i=0;i<8;++i){
        if(O(0,i)){
            kill1.insert(2);
            if(ept1==1)kill2.insert(2);
        }
    }

    if(ept0==1)for(int i=0;i<7;++i){
        if(O(0,i+1) && O(1,i)){
            kill1.insert(3);
            if(ept1==2)kill2.insert(3);
        }
    }
    else if(ept0==2)for(int i=0;i<6;++i){
        if(O(0,i) && O(0,i+1) && O(1,i+2)){
            kill1.insert(3);
        }
    }

    if(ept0==1)for(int i=0;i<7;++i){
        if(O(0,i) && O(1,i+1)){
            kill1.insert(4);
            if(ept1==2)kill2.insert(4);
        }
    }
    else if(ept0==2)for(int i=0;i<6;++i){
        if(O(1,i) && O(0,i+1) && O(0,i+2)){
            kill1.insert(4);
        }
    }

    if(ept0==3)for(int i=0;i<6;++i){
        if(O(0,i) && O(0,i+1) && O(0,i+2)){
            kill1.insert(5);
        }
    }
    else if(ept0==1){
        for(int i=0;i<7;++i){
            if(O(0,i) && O(1,i+1)){
                kill1.insert(5);
                if(ept1==2)kill2.insert(5);
            }
            if(O(1,i) && O(0,i+1)){
                kill1.insert(5);
                if(ept1==2)kill2.insert(5);
            }
        }
        for(int i=0;i<6;++i){
            if(O(1,i) && O(0,i+1) && O(1,i+2)){
                kill1.insert(5);
                if(ept1==3)kill2.insert(5);
            }
        }
    }
}

int main(){
    cin>>stat[1]>>stat[0];
    meow();
    if(kill2.size()){
        for(int i:kill2)cout<<i<<" "; cout<<endl;
        cout<<16<<endl;
    }
    else{
        for(int i:kill1)cout<<i<<" "; cout<<endl;
        cout<<8<<endl;
    }
}
