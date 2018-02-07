#include<bits/stdc++.h>
using namespace std;

int x[1004],y[1004],d[1004];

struct pt{
    int x,y;
    pt(int a,int b):x(a),y(b){}
    bool operator<(const pt &b)const{return x==b.x?y<b.y:x<b.x;}
    bool operator>(const pt &b)const{return x==b.x?y>b.y:x>b.x;}
    bool operator<=(const pt &b)const{return x==b.x?y<=b.y:x<=b.x;}
    bool operator>=(const pt &b)const{return x==b.x?y>=b.y:x>=b.x;}
    bool operator==(const pt &b)const{return x==b.x && y==b.y;}
};

struct seg{
    pt a,b;
    seg(pt _a,pt _b):a(min(_a,_b)),b(max(_a,_b)){}
    bool ispnt(){return a==b;}
    int slope(){return (b.y-a.y)/(b.x-a.x);}
    int offset(){return a.x-a.y*slope();}
    bool in_line(pt x){
        if(x==a || x==b)return 1;
        if(x.x==a.x)return 0;
        if(a==b)return 0;
        return (b.y-a.y)*(x.x-a.x)==(b.x-a.x)*(x.y-a.y);
    }
};

vector<seg> avil(int i){
    vector<seg> rt;
    if(d[i]==0){
        rt.emplace_back(pt(x[i],y[i]),pt(x[i],y[i]));
        return rt;
    }
    rt.emplace_back(pt(x[i],y[i]-d[i]),pt(x[i]+d[i],y[i]));
    rt.emplace_back(pt(x[i]+d[i],y[i]),pt(x[i],y[i]+d[i]));
    rt.emplace_back(pt(x[i],y[i]+d[i]),pt(x[i]-d[i],y[i]));
    rt.emplace_back(pt(x[i]-d[i],y[i]),pt(x[i],y[i]-d[i]));
    return rt;
}

vector<seg> unique(vector<seg> &x){
    vector<seg> rt;
    for(int i=0;i<x.size();++i){
        bool conflict=0;
        for(int j=i+1;j<x.size();++j){
            if(x[i].ispnt()){
                if(x[j].ispnt()){
                    if(x[i].a==x[j].a){
                        conflict=1;
                        break;
                    }
                }
                else{
                    if(x[j].a<=x[i].a && x[i].a<=x[j].b && x[j].in_line(x[i].a)){
                        conflict=1;
                        break;
                    }
                }
            }
            else{
                if(x[j].ispnt()){
                    if(x[i].a<=x[j].a && x[j].a<=x[i].b && x[i].in_line(x[j].a)){
                        conflict=1;
                        x[j]=x[i];
                        break;
                    }
                }
                else{
                    if(x[i].slope()==x[j].slope()){
                        if(x[i].offset()==x[j].offset()){
                            pt lest=max(x[i].a,x[j].a);
                            pt rest=min(x[i].b,x[j].b);
                            if(rest<lest);
                            else if(rest>=lest){
                                x[j]=seg(min(x[i].a,x[j].a),max(x[i].b,x[j].b));
                                conflict=1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(!conflict)rt.push_back(x[i]);
    }
    return rt;
}

vector<seg> merge(vector<seg> &a,vector<seg> b){
    /* cout<<"a: "<<endl;
        for(auto i:a){
            printf("(%d,%d)-(%d,%d)\n",i.a.x,i.a.y,i.b.x,i.b.y);
            fflush(stdout);
        }
    cout<<"b: "<<endl;
        for(auto i:b){
            printf("(%d,%d)-(%d,%d)\n",i.a.x,i.a.y,i.b.x,i.b.y);
            fflush(stdout);
        } */


    vector<seg> rt;
    for(seg &i:a){
        if(i.ispnt()){
            for(seg &j:b){
                if(j.ispnt()){
                    if(i.a==j.a)rt.push_back(i);
                }
                else{
                    // printf("checking line: (%d,%d)-(%d,%d)\n",j.a.x,j.a.y,j.b.x,j.b.y);
                    if(j.a<=i.a && i.a<=j.b && j.in_line(i.a))rt.push_back(i);
                    // cout<<"fin."<<endl;
                }
            }
        }
        else for(seg &j:b){
            if(j.ispnt()){
                if(i.a<=j.a && j.a<=i.b && i.in_line(j.a))rt.push_back(j);
            }
            else{
                if(i.slope()==j.slope()){
                    if(i.offset()!=j.offset())continue;
                    pt lest=max(i.a,j.a);
                    pt rest=min(i.b,j.b);
                    if(rest<lest)continue;
                    if(rest==lest)rt.emplace_back(lest,lest);
                    else rt.emplace_back(lest,rest);
                }
                else{
                    // printf("matching line: (%d,%d)-(%d,%d) and (%d,%d)-(%d,%d)\n",i.a.x,i.a.y,i.b.x,i.b.y,j.a.x,j.a.y,j.b.x,j.b.y);
                    if(abs(i.offset()-j.offset())&1)continue;
                    // cout<<"intersect at int point"<<endl;
                    // cout<<"i slope: "<<i.slope()<<endl;
                    // cout<<"i,j offset: "<<i.offset()<<" , "<<j.offset()<<endl;
                    pt secpnt=pt(i.offset()-i.slope()*(j.offset()-i.offset())/2,i.slope()*(j.offset()-i.offset())/2);
                    // printf("sect point is (%d,%d)\n",secpnt.x,secpnt.y);
                    if(i.a<=secpnt && secpnt<=i.b && j.a<=secpnt && secpnt<=j.b)rt.push_back(seg(secpnt,secpnt));
                }
            }
        }
    }
    
    /* cout<<"rt:"<<endl;
        for(auto i:rt){
            printf("(%d,%d)-(%d,%d)\n",i.a.x,i.a.y,i.b.x,i.b.y);
            fflush(stdout);
        }
    cout<<", go unique"<<endl; */

    return unique(rt);
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>x[i]>>y[i]>>d[i];
    vector<seg> anss=avil(0);
    /* cout<<"avil 0:"<<endl;
        for(auto i:anss){
            printf("(%d,%d)-(%d,%d)\n",i.a.x,i.a.y,i.b.x,i.b.y);
            fflush(stdout);
        } */
    for(int i=1;i<n;++i){
        anss=merge(anss,avil(i));
    /* cout<<"avil "<<i<<":"<<endl;
        for(auto i:anss){
            printf("(%d,%d)-(%d,%d)\n",i.a.x,i.a.y,i.b.x,i.b.y);
            fflush(stdout);
        } */
    } 
    /* cout<<"anss :"<<endl;
        for(auto i:anss){
            printf("(%d,%d)-(%d,%d)\n",i.a.x,i.a.y,i.b.x,i.b.y);
            fflush(stdout);
        }  */
    if(anss.size()==1 && anss[0].ispnt()){
        cout<<anss[0].a.x<<" "<<anss[0].a.y<<endl;
    }
    else if(anss.size()==0)cout<<"impossible"<<endl;
    else cout<<"uncertain"<<endl;
}
