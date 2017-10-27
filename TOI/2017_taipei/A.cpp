#include<bits/stdc++.h>
using namespace std;

void jizz(){cout<<0<<endl; exit(0);}

unordered_map<string,unsigned long long> *st,*tmp;
int main(){
    clock();
    // freopen("in","r",stdin);

    int n; cin>>n;
    st=new unordered_map<string,unsigned long long>(); tmp=new unordered_map<string,unsigned long long>();
    vector<string> str;
    for(int i=0;i<n;++i){
        string s; cin>>s;
        st->insert({s,i});
        str.push_back(s);
    }

    while(clock()/(1.0*CLOCKS_PER_SEC)<=0.45){
        // cout<<"meow"<<endl;
        // for(auto &i:*st)cout<<i<<endl; cout<<endl;
        *tmp=*st;
        for(auto i=st->begin();i!=st->end();++i){
            if(clock()/(1.0*CLOCKS_PER_SEC)>0.45)break;
            for(int j=0;j<n;++j){
                if(clock()/(1.0*CLOCKS_PER_SEC)>0.45)break;
                string nst=i->first+str[j];
                unsigned long long nhh=i->second*47017+j;
                // cout<<"nst : "<<nst<<endl;
                auto it=tmp->find(nst);
                if(it!=tmp->end() && it->second!=nhh)jizz();
                else if(it==tmp->end())tmp->insert({nst,nhh});
            }
        }
        swap(tmp,st);
    }
    cout<<1<<endl;
}
