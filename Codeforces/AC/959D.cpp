#include<bits/stdc++.h>
using namespace std;

bitset<40000006> np;
set<int> pst;
vector<int> p;

void init(){
    for(int i=2;i<40000000;++i){
        if(np[i])continue;
        p.push_back(i);
        pst.insert(i);
        for(auto j=1ll*i*i;j<40000000;j+=i){
            np[j]=1;
        }
    }
}

vector<int> factors;
bool check_coprime(int x){
    factors.clear();
    for(int i:p){
        if(i*i>x)break;
        if(x%i)continue;
        auto it=pst.find(i);
        if(it==pst.end())return 0;
        while(x%i==0)x/=i;
        factors.push_back(i);
    }
    if(x>1){
        auto it=pst.find(x);
        if(it==pst.end())return 0;
        factors.push_back(x);
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    int n,t; cin>>n;
    bool lock=1;
    while(n--){
        cin>>t;
        if(lock){
            if(!check_coprime(t)){
                lock=0;
                for(++t;;++t){
                    if(check_coprime(t)){
                        cout<<t<<" ";
                        for(int i:factors)pst.erase(i);
                        break;
                    }
                }
            }
            else{
                cout<<t<<" ";
                for(int i:factors)pst.erase(i);
            }
        }
        else{
            cout<<*pst.begin()<<" ";
            pst.erase(pst.begin());
        }
    }
    cout<<endl;
}
