#include<bits/stdc++.h>

using namespace std;

int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);*/
/*freopen("iiji","r",stdin);
freopen("jizz","w",stdout);*/
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    stack<char> j;
    char c;

    for(int i=0;i<t;i++){
        if(i)printf("\n");


        while(scanf("%c",&c) != EOF && c != '\n'){
            getchar();
            if(c>='0'&&c<='9'){
                printf("%c",c);
            }
            else if(c=='-'||c=='+'){
                while(j.size() && /*(j.top()!='(')*/ (j.top()=='+'||j.top()=='-'||j.top()=='*'||j.top()=='/')){
                    printf("%c",j.top());//cout<<j.top();
                    j.pop();
                }
                j.push(c);
            }
            else if(c=='*'||c=='/'){
                while(j.size() && (j.top()=='*' || j.top()=='/')){
                    printf("%c",j.top());//cout<<j.top();
                    j.pop();
                }

                j.push(c);
            }

            else if(c=='('){
                j.push(c);
            }
            else if(c==')'){
                while(j.size() && j.top()!='('){
                    printf("%c",j.top());//cout<<j.top();
                    j.pop();
                }
                if(j.size())j.pop();
            }
            //cout<<"now ans "<<ans<<" ";for(int i=0;i<j.size();i++){printf("%d",j[i]);}
        }
        while(j.size()){
            /*if(j.top()!='(')*/printf("%c",j.top());//cout<<j.top();
            j.pop();
        }//getchar();
        printf("\n");

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
                    if(j.size())j.pop();
                }
                j.push(c);
            }
            if(c=='*'||c=='/'){
                while(j.size() && (j.top()=='*' || j.top()=='/')){
                    ans = ans + j.top();
                    if(j.size())j.pop();
                }

                j.push(c);
            }

            if(c=='('){
                j.push(c);
            }
            if(c==')'){
                while(j.top()!='('){
                    ans = ans + j.top();
                    if(j.size())j.pop();
                }
                if(j.size())j.pop();
            }
            if(c=='\n'){
                while(j.size()){
                    ans = ans + j.top();
                    if(j.size())j.pop();
                }
                cout<<ans<<endl;
                break;
            }getchar();
            //cout<<"now ans "<<ans<<" ";for(int i=0;i<j.size();i++){printf("%d",j[i]);}
        }
        cout<<endl;
    }
}*/


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
