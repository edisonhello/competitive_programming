#include<string>
#include<iostream>
#include<sstream>
using namespace std;

string qu,line,ans[6][1005];
int cans[6];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>cans[0];
    for(int i=0;i<cans[0];++i){
        cin>>ans[0][i];
    }
    int qs;
    cin>>qs;
    getline(cin,line);
    for(int q=1;q<=qs;++q){
        getline(cin,line);
        stringstream ss(line);
        int ru=0;
        while(ss>>qu){
            ++ru;
            cans[ru]=0;
            if(qu[0]=='*'&&qu[qu.length()-1]=='*'){
                qu=qu.substr(1,qu.length()-2);
                for(int i=0;i<cans[ru-1];++i){
                    if(ans[ru-1][i].find(qu)!=string::npos){
                        ans[ru][cans[ru]++]=ans[ru-1][i];
                    }
                }
            }
            else if(qu[qu.length()-1]=='*'){
                for(int i=0;i<cans[ru-1];++i){
                    if(ans[ru-1][i].length()<qu.length()-1){
                        continue;
                    }
                    for(int j=0;j<(int)qu.length()-1;++j){
                        if(qu[j]!=ans[ru-1][i][j]){
                            goto nomatch1;
                        }
                    }
                    ans[ru][cans[ru]++]=ans[ru-1][i];
                    nomatch1:;
                }
            }
            else{
                for(int i=0;i<cans[ru-1];++i){
                    if(ans[ru-1][i].length()<qu.length()-1){
                        continue;
                    }
                    for(int j=ans[ru-1][i].length()-1,k=qu.length()-1;k>0;--j,--k){
                        if(ans[ru-1][i][j]!=qu[k]){
                            goto nomatch2;
                        }
                    }
                    ans[ru][cans[ru]++]=ans[ru-1][i];
                    nomatch2:;
                }
            }
        }
        // cout<<ru<<" "<<cans[ru]<<endl;
        cout<<"Query "<<q<<": "<<line<<", "<<cans[ru]<<" item(s) is found.\n";
        for(int i=0;i<cans[ru];++i){
            cout<<ans[ru][i]<<'\n';
        }
        cout<<'\n';
    }
}
