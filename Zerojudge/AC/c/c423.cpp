// copy from TIOJ 1912
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int n,rt;char c,r;string ps;
vector<string> v;
set<string> st;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n>>c>>ps){
    rt=0,r=0;v.clear();st.clear();
    for(char ch:ps){rt+=ch-'0';}
    while(rt>9){rt=(rt/10)+(rt%10);}
    for(int i=0,trt=rt;i<10;++i,trt=rt){
        trt+=i;while(trt>9){trt=(trt/10)+(trt%10);}
        if(trt==c-'0'){
            r=i+'0';
            for(int i=0;i<n;++i){
                v.push_back(ps);
                v.back().insert(i,1,r);
            }
        }
    }
    for(string str:v){st.insert(str);}
    v.clear();
    for(string str:st){v.push_back(str);}
    for(int i=1;i<(int)(v.size())-1;++i){
        cout<<v[i]<<endl;
    }
}}
