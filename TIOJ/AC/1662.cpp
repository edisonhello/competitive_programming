#include<bits/stdc++.h>
using namespace std;
char c;
int main(){
    while((c=getchar())){
        if(c==EOF)break;
        if(c>='a'&&c<='z')c-=32;
        else if(c>='A'&&c<='Z')c+=32;
        else if(c!='\n')c=32;
        putchar(c);
        // cout<<','<<endl;
    }
}
