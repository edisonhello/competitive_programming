#include<iostream>
#include<string>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;cin>>s;
    int dis;cin>>dis;

    char k=s[0],k2=s[1];
    int c;

    if(k=='M')c=1;
    else if(k=='T'&&k2=='u')c=2;
    else if(k=='W')c=3;
    else if(k=='T'&&k2=='h')c=4;
    else if(k=='F')c=5;
    else if(k=='S'&&k2=='a')c=6;
    else if(k=='S'&&k2=='u')c=7;

    c+=dis;

    c%=7;

    if(c==0)cout<<"Sunday\n";
    else if(c==1)cout<<"Monday\n";
    else if(c==2)cout<<"Tuesday\n";
    else if(c==3)cout<<"Wednesday\n";
    else if(c==4)cout<<"Thursday\n";
    else if(c==5)cout<<"Friday\n";
    else if(c==6)cout<<"Saturday\n";

}
