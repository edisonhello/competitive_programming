#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define imnot guagua
using namespace std;

inline int rit(){
    int t=0,key=1;
    char j;
    do{
        j=getchar();
        if(j=='-')key=-1;
    }while((j<'0' || j>'9'));
    do{
        t = t*10+j-'0';
        j=getchar();

    }while((j>='0' && j<='9'));
    return t*key;
}

int main(){
    vector<int> s;s.push_back(1);s.push_back(2);
    sort(s.begin(),s.end());
    cout<<s[0]<<s[1]<<endl;
}
