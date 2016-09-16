#include<bits/stdc++.h>
using namespace std;

map<int,string> ids;
map<string,string> words;

int cnt,done;
string comm;
bool ok[99999];
int main(){
    string s,ss;
    while(cin>>s && s!="jizz"){
        cin>>ss;
        ids[cnt]=s;
        words[s]=ss;
        cnt++;
    }
    srand(time(NULL));
    int now=rand()%cnt;
    done=cnt;
    while(done){
        do now=rand()%cnt;while(ok[now]);

        cout<</*"id="<<now<<" , "<<*/ids[now]<<endl;

        cin>>comm;
        cout<<words[ids[now]]<<endl;
        cin>>comm;

        if(comm[0]=='1'){
            ok[now]=1;
            done--;
        }

        cout<<cnt-done<<" / "<<cnt<<endl;
    }
}
