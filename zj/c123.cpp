#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
};

int n,i,a[1005],j;
string s;
stack<int> st;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    bool fst=0;
    while(cin>>n && n){
        getline(cin,s);
        if(fst)cout<<endl;
        fst++;
        while(getline(cin,s) && s[0]!='0'){
            stringstream ss;
            ss<<s;
            i=1;
            while(ss>>a[i]){
                i++;
            }
            int head=1;
            while(st.size())st.pop();
            bool no=0;
            for(i=1;i<=n;i++){
                again:
                if(a[i]==head){
                    head++;
                    continue;
                }
                else if(st.size() && st.top()==a[i]){
                    st.pop();
                    continue;
                }
                else if(a[i]<head){
                    no=1;
                    break;
                }
                st.push(head);
                head++;
                goto again;
            }
            if(no)cout<<"No\n";
            else cout<<"Yes\n";
        }
    }
}
