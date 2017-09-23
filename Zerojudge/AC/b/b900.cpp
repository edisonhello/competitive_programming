#include<iostream>

using namespace std;

string s[105];
int a[12];

int main(){
    int h,w;cin>>w>>h;
    for(int i=0;i<h;++i){
        cin>>s[i];
    }
    for(int i=1;i<=w;++i){
        a[i]=i;
    }
    for(int i=h-1;i>=0;--i){
        for(int j=1;j<w*2-1;j+=2){
            if(s[i][j]==45){
                swap(a[j/2+1],a[j/2+2]);
            }
        }
    }
    for(int i=1;i<=w;++i){
        if(i-1)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
}
