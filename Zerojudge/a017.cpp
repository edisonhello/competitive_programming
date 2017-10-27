#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define pbi pair<bool,int>
#define pii pair<int,ull>
#define X first
#define Y second

inline pii r(){
    int t=0;char c;
    do{
        c=getchar();
        // cout<<(int)c<<endl;
    }while(c==' ');
    if(c=='\n')return make_pair(0,0);
    if(c=='+')return make_pair(0,1);
    if(c=='-')return make_pair(0,2);
    if(c=='*')return make_pair(0,3);
    if(c=='/')return make_pair(0,4);
    if(c=='%')return make_pair(0,5);
    if(c=='(')return make_pair(0,6);
    if(c==')')return make_pair(0,7);
    do{
        t=t*10+c-'0';
        c=getchar();
        // cout<<(int)c<<endl;
    }while(c>='0'&&c<='9');
    // cout<<(int)c<<endl;
    if(c==10){
        // cout<<"nya"<<endl;
        return make_pair(2,(ull)t);
    }
    return make_pair(1,(ull)t);
}

int main(){
    pii t;
    string first;
    while(cin>>first){
        bool fst = true;
        vector<ull> _;
        vector<ull> n;
        while(1){
            if(!fst){
                t=r();
            }
            if(fst){
                fst=false;
                if(first=="("){
                    t=make_pair(0,6);
                }
                else{
                    ull fstnumb;
                    stringstream ss;
                    ss<<first;
                    ss>>fstnumb;
                    t=make_pair(1,fstnumb);
                }
            }
            // cout<<t.X<<" "<<t.Y<<endl;
            if((t.X==0 && t.Y==0)){
                // cout<<"jizz"<<endl;
                while(_.size()){
                    ull t2=n.back();n.pop_back();
                    ull t1=n.back();n.pop_back();
                    int f=_.back();_.pop_back();
                    if(f==1)n.push_back(t1+t2);
                    if(f==2)n.push_back(t1-t2);
                    if(f==3)n.push_back(t1*t2);
                    if(f==4)n.push_back(t1/t2);
                    if(f==5)n.push_back(t1%t2);
                }
                cout<<n.back()<<endl;
                break;
            }
            if(t.X==2){
                // cout<<"jizz"<<endl;
                n.push_back(t.Y);
                while(_.size()){
                    ull t2=n.back();n.pop_back();
                    ull t1=n.back();n.pop_back();
                    int f=_.back();_.pop_back();
                    if(f==1)n.push_back(t1+t2);
                    if(f==2)n.push_back(t1-t2);
                    if(f==3)n.push_back(t1*t2);
                    if(f==4)n.push_back(t1/t2);
                    if(f==5)n.push_back(t1%t2);
                }
                cout<<n.back()<<endl;
                break;
            }
            if(t.X==1){
                n.push_back(t.Y);
            }
            if(t.X==0){
                if(t.Y==6){
                    _.push_back(6);
                }
                if(t.Y==7){
                    while(_.back()!=6){
                        // cout<<"in 7 loop"<<endl;
                        ull t2=n.back();n.pop_back();
                        ull t1=n.back();n.pop_back();
                        int f=_.back();_.pop_back();
                        if(f==1)n.push_back(t1+t2);
                        if(f==2)n.push_back(t1-t2);
                        if(f==3)n.push_back(t1*t2);
                        if(f==4)n.push_back(t1/t2);
                        if(f==5)n.push_back(t1%t2);
                    }
                    _.pop_back();
                }
                if(t.Y==1||t.Y==2){
                    if(_.size()){
                        int f=_.back();
                        if(f!=6){
                            _.pop_back();
                            ull t2=n.back();n.pop_back();
                            ull t1=n.back();n.pop_back();
                            if(f==1)n.push_back(t1+t2);
                            if(f==2)n.push_back(t1-t2);
                            if(f==3)n.push_back(t1*t2);
                            if(f==4)n.push_back(t1/t2);
                            if(f==5)n.push_back(t1%t2);
                        }
                    }
                    _.push_back(t.Y);
                }
                if(t.Y==3||t.Y==4||t.Y==5){
                    if(_.size()){
                        int f=_.back();
                        if(f==3){
                            _.pop_back();
                            ull t2=n.back();n.pop_back();
                            ull t1=n.back();n.pop_back();
                            n.push_back(t1*t2);
                        }
                        if(f==4){
                            _.pop_back();
                            ull t2=n.back();n.pop_back();
                            ull t1=n.back();n.pop_back();
                            n.push_back(t1/t2);
                        }
                        if(f==5){
                            _.pop_back();
                            ull t2=n.back();n.pop_back();
                            ull t1=n.back();n.pop_back();
                            n.push_back(t1%t2);
                        }
                    }
                    _.push_back(t.Y);
                }
            }
            // cout<<"in n is ";for(int i=0;i<n.size();i++)cout<<n[i]<<" ";cout<<endl;
            // cout<<"in _ is ";for(int i=0;i<_.size();i++)cout<<_[i]<<" ";cout<<endl;
        }
    }
}
