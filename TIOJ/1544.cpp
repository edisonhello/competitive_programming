#include<iostream>
#include<string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    string a,b;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        if(a.length()!=b.length()){
            cout<<(a.length()<=b.length())<<'\n';
            // printf("%d\n",a.length()<=b.length());
        }
        else{
            bool ced=0;
            for(int i=0;i<a.length();i++){
                if(a[i]!=b[i]){
                    cout<<(a[i]<=b[i])<<'\n';
                    // printf("%d\n",a[i]<=b[i]);
                    ced=1;
                    break;
                }
            }
            if(!ced)cout<<"1\n"<<endl;
        }
    }
}
