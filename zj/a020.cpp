#include<bits/stdc++.h>
using namespace std;


int to_n(int n){
    int ret = ((n%10)*9)+(n/10);
    // cout<<ret<<endl;
    return ((n%10)*9)+(n/10);
}
int get(char c){
    if(c=='A')return to_n(10);
    if(c=='B')return to_n(11);
    if(c=='C')return to_n(12);
    if(c=='D')return to_n(13);
    if(c=='E')return to_n(14);
    if(c=='F')return to_n(15);
    if(c=='G')return to_n(16);
    if(c=='H')return to_n(17);
    if(c=='I')return to_n(34);
    if(c=='J')return to_n(18);
    if(c=='K')return to_n(19);
    if(c=='L')return to_n(20);
    if(c=='M')return to_n(21);
    if(c=='N')return to_n(22);
    if(c=='O')return to_n(35);
    if(c=='P')return to_n(23);
    if(c=='Q')return to_n(24);
    if(c=='R')return to_n(25);
    if(c=='S')return to_n(26);
    if(c=='T')return to_n(27);
    if(c=='U')return to_n(28);
    if(c=='V')return to_n(29);
    if(c=='W')return to_n(32);
    if(c=='X')return to_n(30);
    if(c=='Y')return to_n(31);
    if(c=='Z')return to_n(33);
}

int main(){
    string s;
    int ans=0;
    while(cin>>s){
        ans=0;
        if(s.length()!=10||!(s[0]>='A'&&s[0]<='Z')){
            cout<<"fake"<<endl;
            continue;
        }
        ans+=get(s[0]);
        for(int i=1;i<9;i++){
            ans+=(s[i]-'0')*(9-i);
        }
        ans+=s[9]-'0';
        // cout<<ans<<endl;
        if(ans%10==0){
            cout<<"real"<<endl;
        }
        else{
            // if(s.find("S1542878")<6546546)
            cout<<"fake"<<endl;
            // else cout<<s<<endl;
        }
    }
}
