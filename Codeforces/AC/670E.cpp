#include<bits/stdc++.h>
using namespace std;

int front=1,back;
int prv[500009],nxt[500009],link[500009];

int main(){
    int n,m,x; cin>>n>>m>>x; back=n;
    for(int i=1;i<=n;++i)prv[i]=i-1;
    for(int i=1;i<=n;++i)nxt[i]=i+1;
    string s; cin>>s; stack<int> st;
    for(int i=0;i<n;++i){
        if(s[i]=='(')st.push(i+1);
        else{
            link[st.top()]=i+1;
            link[i+1]=st.top();
            st.pop();
        }
    }
    string op; cin>>op; for(char c:op){
        if(c=='L')x=prv[x];
        else if(c=='R')x=nxt[x];
        else{
            int L,R;
            if(s[x-1]=='(')L=x,R=link[x];
            else L=link[x],R=x;
            int LL=prv[L],RR=nxt[R];
            nxt[LL]=RR; prv[RR]=LL;
            if(L==front)front=RR;
            if(R==back)back=LL,x=LL;
            else x=RR;
        }
    }
    for(int x=front;x!=back;x=nxt[x]){
        cout<<s[x-1];
    }
    cout<<s[back-1]<<endl;
}
