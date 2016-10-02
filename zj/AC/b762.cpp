#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string s;
    int kill=0;
    int combo=0;
    int ass=0;
    int die=0;
    while(n--){
        cin>>s;
        if(s=="Get_Kill"){
            kill++;
            combo++;
            if(combo<3){
                cout<<"You have slain an enemie.\n";
            }
            else if(combo==3){
                cout<<"KILLING SPREE!\n";
            }
            else if(combo==4){
                cout<<"RAMPAGE~\n";
            }
            else if(combo==5){
                cout<<"UNSTOPPABLE!\n";
            }
            else if(combo==6){
                cout<<"DOMINATING!\n";
            }
            else if(combo==7){
                cout<<"GUALIKE!\n";
            }
            else if(combo>=8){
                cout<<"LEGENDARY!\n";
            }
        }
        if(s=="Get_Assist"){
            ass++;
        }
        if(s=="Die"){
            if(combo<3){
                cout<<"You have been slained.\n";
            }
            else{
                cout<<"SHUTDOWN.\n";
            }
            die++;
            combo=0;
        }
    }
    cout<<kill<<"/"<<die<<"/"<<ass<<'\n';
}
