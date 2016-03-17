#include<bits/stdc++.h>

using namespace std;

inline char r(){
    char a;bool jizz=false;
    a = getchar();
    if(a=='\n'){
        return a;
    }
    char tmp = getchar();
    return a;
}

int main(){
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    //getchar();
    //getchar();
    while(t--){
        stack<char> j;
        string ans = "";
        while(1){
            char c;scanf("%c",&c);   //cout<<(int)c<<endl;

//getchar();
            if(c>='0'&&c<='9'){
                ans = ans + c;
            }
            if(c=='-'||c=='+'){
                while(j.size() && (j.top()!='(')){
                    ans = ans + j.top();
                    j.pop();
                }
                j.push(c);
            }
            if(c=='*'||c=='/'){
                while(j.size() && (j.top()=='*' || j.top()=='/')){
                    ans = ans + j.top();
                    j.pop();
                }

                j.push(c);
            }

            if(c=='('){
                j.push(c);
            }
            if(c==')'){
                while(j.top()!='('){
                    ans = ans + j.top();
                    j.pop();
                }
                j.pop();
            }
            if(c=='\n'){
                while(j.size()){
                    ans = ans + j.top();
                    j.pop();
                }
                cout<<ans<<endl;
                break;
            }getchar();
            //cout<<"now ans "<<ans<<" ";for(int i=0;i<j.size();i++){printf("%d",j[i]);}
        }
        cout<<endl;
    }
}
/*
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    //getchar();
    //getchar();
    while(t--){
        vector<char> j;
        string ans = "";
        while(1){
            char c;scanf("%c",&c);   //cout<<(int)c<<endl;

//getchar();
            if(c>='0'&&c<='9'){
                ans = ans + c;
            }
            if(c=='-'||c=='+'){
                while(j.size() && (j.back()!='(')){
                    ans = ans + j.back();
                    j.pop_back();
                }
                j.push_back(c);
            }
            if(c=='*'||c=='/'){
                while(j.size() && (j.back()=='*' || j.back()=='/')){
                    ans = ans + j.back();
                    j.pop_back();
                }

                j.push_back(c);
            }

            if(c=='('){
                j.push_back(c);
            }
            if(c==')'){
                while(j.back()!='('){
                    ans = ans + j.back();
                    j.pop_back();
                }
                j.pop_back();
            }
            if(c=='\n'){
                while(j.size()){
                    ans = ans + j.back();
                    j.pop_back();
                }
                cout<<ans<<endl;
                break;
            }getchar();
            //cout<<"now ans "<<ans<<" ";for(int i=0;i<j.size();i++){printf("%d",j[i]);}
        }
        cout<<endl;
    }
}
*/
