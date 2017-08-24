#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    int n,a,b,t;
    cin>>n>>a>>b>>t;
    string s;cin>>s;
    int *time=new int[n];
    int cnt=0;
    int gofront=0;
    int goback=0;
    int been=0;

    for(int i=0;i<n;i++){
        int tmp=0;
        tmp++;
        tmp+=a;
        if(s[i] != 'h'){
            tmp+=b;
        }
        time[i] = tmp;
    }

    tmp[0] -= a;




/*
    if(s[0] == 'h'){
        been++;
    }

    while(1){
        if(been >= t || cnt == n)break;
        if(s[cnt] == 'h'){
            been++;
            cnt++;
            been+=a;
            continue;
        }
        else{
            been+=b;
            s[cnt] = 'h';
        }
    }*/
    cout<<cnt<<endl;
}
