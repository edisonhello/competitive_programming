#include<bits/stdc++.h>
using namespace std;
#define PQ priority_queue

bool sml(const string &a,const string &b){
    return a.length()!=b.length()?a.length()<b.length():a<b;
}
bool bg(const string &a,const string &b){
    return a.length()!=b.length()?a.length()>b.length():a>b;
}
int n,s,f,e,t;
string cm,pw,tk;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n){
        stack<string> _1;
        queue<string> _2;
        PQ<string,vector<string>,decltype(&sml)> _3(&sml);
        PQ<string,vector<string>,decltype(&bg)> _4(&bg);
        while(n--){
            cin>>cm;
            if(cm[2]=="ダメよ～"[2]){
                cin>>s>>pw;
                if(s==1)_1.push(pw);
                if(s==2)_2.push(pw);
                if(s==3)_3.push(pw);
                if(s==4)_4.push(pw);
            }
            if(cm[2]=="しかしお兄"[2]){
                cin>>f>>e;
                if(f==1&&_1.size()){tk=_1.top();_1.pop();}
                else if(f==2&&_2.size()){tk=_2.front();_2.pop();}
                else if(f==3&&_3.size()){tk=_3.top();_3.pop();}
                else if(f==4&&_4.size()){tk=_4.top();_4.pop();}
                else continue;
                if(e==1)_1.push(tk);
                if(e==2)_2.push(tk);
                if(e==3)_3.push(tk);
                if(e==4)_4.push(tk);
            }
            if(cm[2]=="くやしい…"[2]){
                cin>>t;
                if(t==1&&_1.size()){tk=_1.top();_1.pop();cout<<tk<<'\n';}
                else if(t==2&&_2.size()){tk=_2.front();_2.pop();cout<<tk<<'\n';}
                else if(t==3&&_3.size()){tk=_3.top();_3.pop();cout<<tk<<'\n';}
                else if(t==4&&_4.size()){tk=_4.top();_4.pop();cout<<tk<<'\n';}
                else cout<<"イヤ...やめてよ...お兄ちゃん...壊れる\n";
            }
        }
    }
}
