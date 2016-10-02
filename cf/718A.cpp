#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    int pos=s.find('.');
    int sto=n;
    int opt=pos+1;
    bool dosth=1;
    rst:
    if(!dosth || !t){
        goto end;
    }
    dosth=0;
    for(int i=opt;i<sto;i++){
        if(s[i]>'4'){
            --t;
            dosth=1;
            if(i==pos+1){
                ++s[i-2];
                for(int k=i-2;k>=0;k--){
                    if(s[k]>'9'){
                        if(k==0){
                            cout<<1;
                            s[k]='0';
                            for(int l=0;l<pos;l++){
                                cout<<s[l];
                            }
                            cout<<endl;
                            return 0;
                        }
                        s[k]='0';
                        ++s[k-1];
                        opt=k-2;
                    }
                    else{
                        for(int l=0;l<pos;l++){
                            cout<<s[l];
                        }
                        cout<<endl;
                        return 0;
                    }
                }
            }
            else{
                ++s[i-1];
                sto=i;
                for(int j=i-1;j>pos;j--){
                    if(s[j]>'9'){
                        if(j==pos+1){
                            ++s[j-2];
                            sto=j-1;
                            for(int k=j-2;k>=0;k--){
                                if(s[k]>'9'){
                                    if(k==0){
                                        cout<<1;
                                        s[k]='0';
                                        for(int l=0;l<pos;l++){
                                            cout<<s[l];
                                        }
                                        cout<<endl;
                                        return 0;
                                    }
                                    s[k]='0';
                                    ++s[k-1];
                                    opt=k-1;
                                }
                                else{
                                    for(int l=0;l<pos;l++){
                                        cout<<s[l];
                                    }
                                    cout<<endl;
                                    return 0;
                                }
                            }
                        }
                        else{
                            ++s[j-1];
                            sto=j;
                            opt=j-2;
                        }
                    }
                    else break;
                }
            }
            goto rst;
        }
    }
    end:;
    for(int i=0;i<sto;++i){
        cout<<s[i];
    }
    cout<<endl;
}
