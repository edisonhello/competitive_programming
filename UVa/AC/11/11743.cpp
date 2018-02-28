#include<bits/stdc++.h>
using namespace std;

int de(int x){
    int rt=0;
    while(x)rt+=x%10,x/=10;
    return rt;
}
int main(){
    int n; cin>>n; while(n--){
        char cre[19];
        scanf("%s %s %s %s\n",cre,cre+4,cre+8,cre+12);
        // printf("%s\n",cre);
        int add=0;
        for(int i=0;i<16;i+=2)add+=de((cre[i]-'0')*2);
        for(int i=1;i<16;i+=2)add+=cre[i]-'0';
        if(add%10)cout<<"Invalid"<<endl;
        else cout<<"Valid"<<endl;
    }
}
