#include<bits/stdc++.h>
using namespace std;
int main(){
    int su[9][9];
    goback:
    while(cin>>su[0][0]>>su[0][1]>>su[0][2]>>su[0][3]>>su[0][4]>>su[0][5]>>su[0][6]>>su[0][7]>>su[0][8]){
        for(int i=1;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>su[i][j];

            }
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                su[i][j]--;
                // cout<<su[i][j]<<" ";
            }
            // cout<<endl;
        }

        for(int i=0;i<9;i++){
            bool f1=false,f2=false;
            bool a1[9]={0},a2[9]={0};
            for(int j=0;j<9;j++){
                if(a1[su[i][j]]==1){
                    // cout<<"hereij"<<i<<j<<endl;
                    f1=true;
                }
                a1[su[i][j]]=1;
                if(a2[su[j][i]]==1){
                    // cout<<"hereij2"<<i<<j<<endl;
                    f2=true;
                }
                a2[su[j][i]]=1;
                // for(int k=0;k<9;k++)cout<<a1[k]<<" ";cout<<endl;
                // for(int k=0;k<9;k++)cout<<a2[k]<<" ";cout<<endl;
            }
            if(f1||f2){
                cout<<"no"<<endl;
                // cout<<"herei"<<i<<endl;
                goto goback;
            }
        }

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                bool f=false;
                bool a[9]={0};
                memset(a,0,9*sizeof(bool));
                for(int ii=0;ii<3;ii++){
                    for(int jj=0;jj<3;jj++){
                        if(a[su[3*i+ii][3*j+jj]]==1){
                            f=true;
                        }
                        a[su[3*i+ii][3*j+jj]]=1;
                    }
                }
                if(f){
                    cout<<"no"<<endl;
                    goto goback;
                }
            }
        }
        cout<<"yes"<<endl;
    }
}
