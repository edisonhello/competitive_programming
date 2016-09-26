#include<bits/stdc++.h>
using namespace std;
int ts,n,sl,cl,fail[10005],cnt;
char samp[10005],comp[10005];

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>ts;
    while(ts--){
        cin>>samp; sl=strlen(samp);
        cin>>n;
        while(n--){
            cnt=0;
            cin>>comp; cl=strlen(comp);
            if(cl>sl){
                cout<<"0\n";
                continue;
            }
            fail[0]=0;
            for(int i=1;i<cl;i++){ // counting fail function
                fail[i]=(comp[fail[i-1]]==comp[i]?fail[i-1]+1:(comp[0]==comp[i]?1:0));
                // cout<<i<<","<<comp[fail[i-1]]<<' '<<comp[i]<<endl;
            }
            // cout<<"fail=";for(int i=0;i<cl;i++)cout<<fail[i]<<" ";cout<<endl;
            for(int i=0,j=0;(i+j)<sl;j++){
                if(samp[i+j]==comp[j]){
                    if(j==cl-1){
                        // cout<<"afs"<<endl;
                        cnt++;
                        i+=(cl-fail[j]);
                        j-=(cl-fail[j]);
                        continue;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    i+=(j-fail[j]+1);//=fail[j-1]+1;
                    j=fail[j]-1;
                }
            }
            cout<<cnt<<'\n';
        }
    }
}
