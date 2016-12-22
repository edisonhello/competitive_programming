#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

int A[2030][2030],B[2030][2030];


int main(){
    int n,ts;cin>>ts;while(ts--){
        cin>>n;
        int t;
        ll s;
        for(int i=0,j;i<n;++i){
            for(j=0;j<n;++j){
                cin>>A[i][j];
            }
        }
        for(int i=0,j;i<n;++i){
            for(j=0;j<n;++j){
                cin>>B[i][j];
            }
        }
        for(int i=0,j;i<n;++i){
            for(j=0;j<n;++j){
                cin>>t;
                s=0;
                for(int k=0;k<n;++k){
                    s+=A[i][k]*B[k][j];
                }
                if(t!=s){
                    cout<<"QAQ!\n";
                    goto next;
                }
            }
        }
        cout<<"Loli is god.\n";
        next:;
    }
}
