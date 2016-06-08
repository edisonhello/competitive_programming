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
                r=r*26+s[i]-'A'+1;
            }
        }
        for(;s.length();i++){
            c=c*10+s[i]-'0';
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
        i++;
        for(;i<s.length();i++){
            c=c*10+s[i]-'0';
        }
        string rstr="";
        while(r>26){
            rstr=rstr+(char)(r%26+'A');
        }
        cout<<rstr<<c<<endl;
    }
}

int main(){
    int n;cin>>n;
    for(int t=0;t<n;t++){
        string s;cin>>s;
        if(chk(s)){//s==BC55
            cout<<"type 1"<<endl;
            trans(s,1);
        }
        else{//s==R23C55
            cout<<"type 0"<<endl;
            trans(s,0);
        }
    }
}
