#include<bits/stdc++.h>
using namespace std;

int n,m;
map<int,int> id;
vector<int> a,b,c;

int inslan(int lan){
    // cout<<"inserting lan id = "<<lan;
    if(id.find(lan)==id.end()){
        id[lan]=id.size();
    }
    // cout<<" , res = "<<id[lan]<<endl;
    return id[lan];
}

int getid(int lan){
    // cout<<"finding lan id = "<<lan;
    if(id.find(lan)==id.end()){
        // cout<<" , res = -1"<<endl;
        return -1;
    }
    // cout<<" , res = "<<id[lan]<<endl;
    return id[lan];
}

void pushit(int it){
    if(it<=a.size()){
        a[it-1]++;
        // cout<<"a["<<it<<"-1]++ = "<<a[it-1]<<endl;
    }
    else{
        a.push_back(1);
        // cout<<"pushed "<<it<<" = 1"<<endl;
    }
    // cout<<"a["<<it-1<<"]="<<a[it-1]<<endl;
}

int findit(int lan){
    int gotid=getid(lan);
    if(gotid==-1){
        return 0;
    }
    else{
        return a[gotid-1];
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        pushit(inslan(t));
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int t;cin>>t;
        b.push_back(findit(t));
    }
    for(int i=0;i<m;i++){
        int t;cin>>t;
        c.push_back(findit(t));
    }

    int mx=-9898989,now=-1,mx2=-98598989;
        // cout<<"b[i] ";
    for(int i=0;i<b.size();i++){
        // cout<<b[i]<<" ";
        if(b[i]>mx){
            mx=b[i];
            mx2=c[i];
            now=i;
        }
        else if(b[i]==mx){
            if(c[i]>mx2){
                mx2=c[i];
                now=i;
            }
        }
    }
    // cout<<endl;
    cout<<now+1<<endl;
}
