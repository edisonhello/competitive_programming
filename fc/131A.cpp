#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;cin>>a;//if(a=="OOPS"){cout<<"oops"<<endl;return 0;}
    if(a[0]>=97 && a[0]<=122){//a[0]-=32;
        bool fl=false;
        for(int i=1;i<a.length();i++){
            if(a[i]>=97&&a[i]<=122){
                fl=true;break;
            }
        }
        if(fl){
            cout<<a<<endl;
            return 0;
        }else{
            a[0]-=32;
            for(int i=1;i<a.length();i++){
                a[i]+=32;
            }
            cout<<a<<endl;
            return 0;
        }
    }
    else{//cout<<endl;
        bool fl=false;
        for(int i=0;i<a.length();i++){
            if(a[i]>=97&&a[i]<=122){   //cout<<endl;
                fl=true;
                break;
            }
        }
        if(fl){
            cout<<a<<endl;return 0;
        }
        else{
            for(int i=0;i<a.length();i++){
                a[i]+=32;
            }
            cout<<a<<endl;
            return 0;
        }
    }
}
