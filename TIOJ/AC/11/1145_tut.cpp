#include<bits/stdc++.h>
using namespace std;

int info[155];

int gmn(int,int);

bitset<155> vmx[155];
int rmx[155][155];
int gmx(int l,int r){
    if(l==r)return info[l];
    if(vmx[l][r])return rmx[l][r];
    vmx[l][r]=1; rmx[l][r]=-2147483648;
    for(int i=l+1;i<r;++i)if(info[i]<0){
        if(info[i]==-1)rmx[l][r]=max(rmx[l][r],gmx(l,i-1)+gmx(i+1,r));
        else if(info[i]==-2)rmx[l][r]=max(rmx[l][r],gmx(l,i-1)-gmn(i+1,r));
        else rmx[l][r]=max(rmx[l][r],max(max(gmx(l,i-1)*gmx(i+1,r),gmx(l,i-1)*gmn(i+1,r)),max(gmn(l,i-1)*gmx(i+1,r),gmn(l,i-1)*gmn(i+1,r))));
    }
    // cout<<"rmx "<<l<<" "<<r<<" "<<rmx[l][r]<<endl;
    return rmx[l][r];
}

bitset<155> vmn[155];
int rmn[155][155];
int gmn(int l,int r){
    if(l==r)return info[l];
    if(vmn[l][r])return rmn[l][r];
    vmn[l][r]=1; rmn[l][r]=2147483647;
    for(int i=l+1;i<r;++i)if(info[i]<0){
        if(info[i]==-1)rmn[l][r]=min(rmn[l][r],gmn(l,i-1)+gmn(i+1,r));
        else if(info[i]==-2)rmn[l][r]=min(rmn[l][r],gmn(l,i-1)-gmx(i+1,r));
        else rmn[l][r]=min(rmn[l][r],min(min(gmx(l,i-1)*gmx(i+1,r),gmx(l,i-1)*gmn(i+1,r)),min(gmn(l,i-1)*gmx(i+1,r),gmn(l,i-1)*gmn(i+1,r))));
        // if(l==2 && r==6)cout<<i<<" "<<info[i]<<" "<<rmn[l][r]<<endl;
    }
    // cout<<"rmn "<<l<<" "<<r<<" "<<rmn[l][r]<<endl;
    return rmn[l][r];
}


int main(){
    string s; cin>>s;
    int t=0,ptr=0;
    for(char c:s){
        if(c>='0' && c<='9')t=t*10+c-'0';
        else{
            info[ptr++]=t; t=0;
            if(c=='+')info[ptr++]=-1;
            else if(c=='-')info[ptr++]=-2;
            else info[ptr++]=-3;
        }
    }
    info[ptr++]=t;
    cout<<gmx(0,ptr-1)<<endl;
}
