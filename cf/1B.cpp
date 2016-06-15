#include<bits/stdc++.h>
using namespace std;

int chk(string s){
    int rec=0;
    int i;
    for(i=0;i<s.length();i++){
        if(s[i]<'A'||s[i]>'Z')break;
    }
    for(;i<s.length();i++){
        if(s[i]<'0'||s[i]>'9')break;
    }
    if(i==s.length())return 1;//BC55
    return 0;//R23C55
}

void trans(string s,int type){
    if(type){
        int i;
        int r=0;
        int c=0;
        for(i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                c=c*26+s[i]-'A'+1;
            }
            else{
                break;
            }
        }
        // cout<<"jizz"<<endl;
        for(;i<s.length();i++){
            r=r*10+s[i]-'0';
        }
        cout<<"R"<<r<<"C"<<c<<endl;
    }
    else{
        int i;
        int r=0;
        int c=0;
        for(i=1;i<s.length();i++){
            if(s[i]=='C')break;
            r=r*10+s[i]-'0';
        }
        // cout<<r<<endl;
        i++;
        for(;i<s.length();i++){
            c=c*10+s[i]-'0';
        }
        // cout<<c<<endl;
        string cstr="";
        while(c){
            // cout<<c%26<<endl;
            if(c%26==0){
                cstr=(char)(25+'A')+cstr;
                c/=26;c--;
            }
            else{
                cstr=(char)(c%26+'A'-1)+cstr;
                c/=26;
            }
        }
        cout<<cstr<<r<<endl;
    }
}

int main(){
    int n;cin>>n;
    for(int t=0;t<n;t++){
        string s;cin>>s;
        if(chk(s)){//s==BC55
            // cout<<"type 1"<<endl;
            trans(s,1);
        }
        else{//s==R23C55
            // cout<<"type 0"<<endl;
            trans(s,0);
        }
    }
}
