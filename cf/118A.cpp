#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;cin>>a;
    for(int i=0;i<a.length();i++){
        if(a[i]!='a'&&a[i]!='A'&&a[i]!='o'&&a[i]!='O'&&a[i]!='I'&&a[i]!='i'&&a[i]!='E'&&a[i]!='e'&&a[i]!='U'&&a[i]!='u'&&a[i]!='y'&&a[i]!='Y'){
            printf(".%c", (a[i]<=96 ? a[i]+32 : a[i] )) ;
        }
    }cout<<endl;
}
