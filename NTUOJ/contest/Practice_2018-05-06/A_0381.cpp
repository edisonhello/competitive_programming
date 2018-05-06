#include<bits/stdc++.h>
using namespace std;
#define int long long

struct pt{
    int x,y;
    pt(int x,int y):x(x),y(y){}
};
pt operator+(const pt &a,const pt &b){
    return pt(a.x+b.x,a.y+b.y);
}
pt operator-(const pt &a,const pt &b){
    return pt(a.x-b.x,a.y-b.y);
}
int operator^(const pt &a,const pt &b){
    return a.x*b.y-a.y*b.x;
}

int32_t main(){
    int ts; cin>>ts; while(ts--){
        string s; cin>>s;
        vector<pt> po;
        pt now(0,0);
        po.push_back(now);
        for(char c:s){
            if(c=='1')now=now+pt(-1,-1);
            if(c=='2')now=now+pt(0,-1);
            if(c=='3')now=now+pt(1,-1);
            if(c=='4')now=now+pt(-1,0);
            if(c=='5')break;
            if(c=='6')now=now+pt(1,0);
            if(c=='7')now=now+pt(-1,1);
            if(c=='8')now=now+pt(0,1);
            if(c=='9')now=now+pt(1,1);
            po.push_back(now);
        }
        int tot=0;
        for(int i=1;i<po.size();++i){
            tot+=po[i]^po[i-1];
        }
        tot=abs(tot);
        cout<<(tot>>1)<<".";
        cout<<(tot&1?'5':'0')<<endl;
    }
}
