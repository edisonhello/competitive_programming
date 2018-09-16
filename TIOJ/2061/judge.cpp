#include <fstream>
#include <iostream>
using namespace std;

template <class It> bool is_scq(It f1, It l1, It f2, It l2) {
  for (; f2 != l2; ++f2) if (*f1 == *f2 && ++f1 == l1) return true;
  return false;
}
template <class It> bool is_pld(It fr, It ba) {
  for (--ba; fr != ba && fr != next(ba); ++fr, --ba) if (*fr != *ba) return false;
  return true;
}

int cnt[255];
int main(int argc,char** argv){
    fstream fs_user(argv[1],ios::in);
    fstream fs_input(argv[2],ios::in);
    fstream fs_output(argv[3],ios::in);
    string user,in,out; 
    fs_user>>user;
    fs_input>>in;
    fs_output>>out;
    for(char c:user)++cnt[c];

    if(!is_scq(user.begin(),user.end(),in.begin(),in.end()))exit((cout<<"jizz!1"<<endl,0));
    if(!is_pld(user.begin(),user.end()))exit((cout<<"jizz!2"<<endl,0));

    if(out.size()>=1000u){ if(user.size()<1000u)exit((cout<<"jizz!3"<<endl,0)); }
    else{ if(user.size()!=out.size())exit((cout<<"jizz!4"<<endl,0)); }
    cout<<0<<endl;
}
