#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<utility>
using namespace std;

set<string> st;

int main(){
    string s;
    cin>>s;
    int l=(int)s.length();
    s=s+s;
    for(int i=0;i<l;++i){
        st.insert(s.substr(i,l));
    }
    cout<<st.size()<<endl;
}
