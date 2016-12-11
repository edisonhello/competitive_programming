#include<iostream>
using namespace std;
#include<unordered_map>
#define X first
#define Y second

unordered_map<string,int> Ntonum,Wtonum;
unordered_map<int,string> numtoN,numtoW;
bool deled[100005];

int main(){
    int person=1;
    string command,a,b;
    char chr;
    ios_base::sync_with_stdio(0);
    while(cin>>command){
        if(command[0]=='a'){
            cin>>a>>b;
            Ntonum[a]=person;
            Wtonum[b]=person;
            numtoN[person]=a;
            numtoW[person]=b;
            ++person;
        }
        else if(command[0]=='c'){
            cin>>chr>>a;
            if(chr=='n'){
                auto it=Ntonum.find(a);
                if(it==Ntonum.end()){cout<<"Not found.\n";continue;}
                int num=it->Y;
                if(deled[num]){cout<<"Not found.\n";continue;}
                b=numtoW[num];
                cout<<a<<" "<<b<<endl;
            }
            else if(chr=='w'){
                auto it=Wtonum.find(a);
                if(it==Wtonum.end()){cout<<"Not found.\n";continue;}
                int num=it->Y;
                if(deled[num]){cout<<"Not found.\n";continue;}
                b=numtoN[num];
                cout<<b<<" "<<a<<endl;
            }
        }
        else{
            cin>>chr>>a;
            if(chr=='n'){
                auto it=Ntonum.find(a);
                deled[it->Y]=1;
                Ntonum.erase(it);
            }
            else if(chr=='w'){
                auto it=Wtonum.find(a);
                deled[it->Y]=1;
                Wtonum.erase(it);
            }
        }
    }
}
