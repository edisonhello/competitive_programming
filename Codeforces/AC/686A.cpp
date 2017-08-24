#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
    ull n,m;
    cin>>n>>m;

    ull s=0;

    for(int i=0;i<n;i++){
        string c;ull q;
        cin>>c>>q;
        if(c=="+"){
            m+=q;
        }
        else{
            if(m<q){
                s++;
            }
            else{
                m-=q;
            }
        }
    }

    cout<<m<<" "<<s<<endl;
}
