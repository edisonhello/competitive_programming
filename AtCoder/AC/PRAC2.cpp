#include<bits/stdc++.h>
using namespace std;
namespace solve57{

void go(vector<vector<int>> &now){
    while(now.size()>1u){
        for(int i=0;i<5;++i){
            for(int j=i+1;j<5;++j){
                int c1=0,c2=0;
                for(auto &v:now){
                    if(v[i]<v[j])++c1;
                    else ++c2;
                }
                // cout<<"if q "<<i<<" "<<j<<" , res: "<<c1<<" "<<c2<<endl;
                if(c1<=(now.size()+1)/2 && c2<=(now.size()+1)/2 && now.size()>1u){
                    // cout<<"now: "<<endl;
                    // for(auto &v:now){for(int i:v)cout<<i<<" "; cout<<endl;}
                    cout<<"? "; cout<<char(i+'A')<<" "<<char(j+'A')<<endl;
                    char res; cin>>res;
                    vector<vector<int>> tmp;
                    if(res=='<'){
                        for(auto &v:now){
                            if(v[i]<v[j])tmp.push_back(v);
                        }
                    }
                    else{
                        for(auto &v:now){
                            if(v[i]>v[j])tmp.push_back(v);
                        }
                    }
                    now.swap(tmp);
                    // cout<<"become: "<<endl;
                    // for(auto &v:now){for(int i:v)cout<<i<<" "; cout<<endl;}
                }
            }
        }
    }
    int pos[5];
    for(int i=0;i<5;++i)pos[now[0][i]]=i;
    cout<<"! ";
    for(int i=0;i<5;++i)cout<<char(pos[i]+'A');
    cout<<endl;
    exit(0);
}

int a[5];
int main(){
    vector<vector<int>> now;
    for(int i=0;i<5;++i)a[i]=i;
    vector<int> tmp(5,0);
    do{
        for(int i=0;i<5;++i)tmp[i]=a[i];
        now.push_back(tmp);
    }while(next_permutation(a,a+5));
    go(now);
}

}

namespace solve26{

int a[26];
int main(){
    a[0]=0;
    for(int i=1;i<26;++i){
        int L=0,R=i;
        while(R>L){
            int mid=(L+R)>>1;
            cout<<"? "<<char(a[mid]+'A')<<" "<<char(i+'A')<<endl;
            char res; cin>>res;
            if(res=='<'){
                L=mid+1;
            }
            else R=mid;
        }
        a[i]=i;
        for(;L<i;++L)swap(a[i],a[L]);
    }
    cout<<"! "; for(int i=0;i<26;++i)cout<<char(a[i]+'A'); cout<<endl;
    exit(0);
}

}

int main(){
    int n,q; cin>>n>>q;
    if(n==5 && q==7)solve57::main();
    else if(n==26)solve26::main();
    else cout<<"JIZZ!"<<endl;
}
