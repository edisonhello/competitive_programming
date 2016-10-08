#include<bits/stdc++.h>
using namespace std;

string _(string pre,string in){
    // cout<<"pre="<<pre<<", in="<<in<<endl;
    assert(pre.length()==in.length());
    if(pre.length()<=1)return pre;
    int in_pos=in.find(pre[0]);
    string left_pre = pre.substr(1,in_pos);
    string right_pre = pre.substr(in_pos+1,pre.length()-in_pos-1);
    string left_in = in.substr(0,in_pos);
    string right_in = in.substr(in_pos+1,pre.length()-in_pos-1);

    // cout<<left_in<<" "<<right_in<<endl;
    return _(left_pre,left_in)+_(right_pre,right_in)+pre[0];
}

int main(){
    string pre,in;
    while(cin>>pre>>in){
        string ans = _(pre,in);
        cout<<ans<<endl;
    }
}
