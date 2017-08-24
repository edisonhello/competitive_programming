#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<sstream>
vector<char> rec;

int main(){
    char c;int n;
    int pl=0,mi=0;
    while(1){
        cin>>c;
        if(c=='=')break;
        else if(c=='?')continue;
        else if(c=='+')++pl;rec.push_back(c);
        else if(c=='-')++mi;rec.push_back(c);
    }
    cin>>n;
    if((mi && !pl)){cout<<"Impossible\n";return 0;}
    stringstream ss;
    ss<<"Possible\n";
    if(mi-pl>0){
        ss<<n<<" ";
        int buffer=mi-pl;
        for(char c:rec){
            if(c=='+' && buffer>0){
                if(buffer+1<=n){
                    ss<<c<<" "<<buffer+1<<" ";
                    buffer=0;
                }
                else{
                    buffer-=(n-1);
                    ss<<c<<" "<<n<<" ";
                }
            }
            else ss<<c<<" "<<1<<" ";
        }
        ss<<"= "<<n<<endl;
        if(buffer>0)cout<<"Impossible\n";
        else{
            string tmp;
            while(getline(ss,tmp))cout<<tmp<<endl;;
        }
    }
    else{
        int buffer=mi-pl;
        if(n+buffer>0){
            ss<<n+buffer<<" ";
            buffer=0;
        }
        else{
            ss<<1<<" ";
            buffer+=(n-1);
        }
        for(char c:rec){
            if(c=='-' && buffer<0){
                // cout<<buffer<<endl;
                if(buffer+n>0){
                    ss<<c<<" "<<1-buffer<<" ";
                    buffer=0;
                }
                else{
                    ss<<c<<" "<<n<<" ";
                    buffer+=(n-1);
                }
            }
            else ss<<c<<" "<<1<<" ";
        }
        ss<<"= "<<n<<endl;
        if(buffer<0)cout<<"Impossible\n";
        else{
            string tmp;
            while(getline(ss,tmp))cout<<tmp<<endl;;
        }
    }
}
