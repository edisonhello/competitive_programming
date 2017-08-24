#include<bits/stdc++.h>

using namespace std;

struct order{
    int day;
    int val;
    int req_f,req_s;
};

struct order_dp{
    int day;
    int val;
    int
};

bool operator<(const order &a,const order &b){
    return a.day < b.day;
}

int main(){
    ios_base::sync_with_stdio(0);
    int n,k,a,b,q;cin>>n>>k>>a>>b>>q;
    vector<order> od;

    for(int i=0;i<q;i++){
        int com;cin>>com;
        if(com==1){
            order t;cin>>t.day>>t.val;
            t.req_f = t.val / a;
            t.req_s = t.val / b;
            od.push_back(t);
        }
        if(com==2){
            sort(od.begin(),od.end());
            int when;cin>>when;
            int work=0;
            int i;
            for(i=0;od[i].day<when && i<od.size();i++){
                work+=od[i].val;
            }
            work -= (when-1)*b;
            if(work<0)work=0;
            for(;od[i].day<=when+k && i<od.size();i++){}
            i--;
            for(;i<od.size();i++){
                work+=od[i].val;
            }
            work -= (n-when)*a;
            if(work<=0){cout<<od.size()<<endl;}
            else{

            }
        }
    }
}
