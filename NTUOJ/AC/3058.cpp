#include<bits/stdc++.h>
using namespace std;

struct card{
    int f,x;
};
bool operator==(const card &a,const card &b){
    return a.f==b.f && a.x==b.x;
}
bool operator<(const card &a,const card &b){
    if(a.x==b.x)return a.f>b.f;
    else return a.x>b.x;
}

void parse(string s,vector<card> &v){
    stringstream ss(s);
    while(ss>>s){
        card tmp;
        if(s[0]=='S')tmp.f=4;
        else if(s[0]=='H')tmp.f=3;
        else if(s[0]=='D')tmp.f=2;
        else if(s[0]=='C')tmp.f=1;

        if(s[1]=='A')tmp.x=14;
        else if(s[1]=='K')tmp.x=13;
        else if(s[1]=='Q')tmp.x=12;
        else if(s[1]=='J')tmp.x=11;
        else if(s[1]=='T')tmp.x=10;
        else if(s[1]=='9')tmp.x=9;
        else if(s[1]=='8')tmp.x=8;
        else if(s[1]=='7')tmp.x=7;
        else if(s[1]=='6')tmp.x=6;
        else if(s[1]=='5')tmp.x=5;
        else if(s[1]=='4')tmp.x=4;
        else if(s[1]=='3')tmp.x=3;
        else if(s[1]=='2')tmp.x=2;
        
        v.push_back(tmp);
    }
}

#define cards vector<card>

int SS(cards &a){
    for(int i=1;i<5;++i)if(a[i].f!=a[i-1].f)return 0;
    return 1;
}

int RSF(cards &a){
    if(!SS(a))return 0;
    for(int i=0;i<5;++i)if(a[i].x!=14-i)return 0;
    return 1;
}

int SF(cards &a){
    if(!SS(a))return 0;
    if(a[0].x==14){
        if(a[1].x==5 && a[2].x==4 && a[3].x==3 && a[4].x==2)return 1;
    }
    for(int i=1;i<5;++i)if(a[i].x!=a[i-1].x-1)return 0;
    return 1;
}
int _SF(cards &a,cards &b){
    bool same=1;
    for(int i=0;i<5;++i)if(a[i].x!=b[i].x)same=0;
    if(same)return 0;
    if(a[0].x==14 && a[1].x==5)return 1;
    if(b[0].x==14 && b[1].x==5)return 0;
    return b[0].x>a[0].x;
}

int FK(cards &a){
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(a[j].x==i)++c;
        }
        if(c==4)return 1;
    }
    return 0;
}
int _FK(cards &a,cards &b){
    int a4=-1,a1=-1,b4=-1,b1=-1;
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(a[j].x==i)++c;
        }
        if(c==4)a4=i;
        else if(c==1)a1=i;
        c=0;
        for(int j=0;j<5;++j){
            if(b[j].x==i)++c;
        }
        if(c==4)b4=i;
        else if(c==1)b1=i;
    }
    if(a4==b4)return a1<b1;
    else return a4<b4;
}

int FH(cards &a){
    int g3=0,g2=0;
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(a[j].x==i)++c;
        }
        if(c==3)g3=i;
        if(c==2)g2=i;
    }
    if(g3 && g2)return 1;
    return 0;
}
int _FH(cards &a,cards &b){
    pair<int,int> aa,bb;
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(a[j].x==i)++c;
        }
        if(c==3)aa.first=i;
        if(c==2)aa.second=i;
    }
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(b[j].x==i)++c;
        }
        if(c==3)bb.first=i;
        if(c==2)bb.second=i;
    }
    return bb>aa;
}

int F(cards &a){
    return SS(a);
}
int _F(cards &a,cards &b){
    for(int i=0;i<5;++i){
        if(a[i].x==b[i].x){}
        else return a[i].x<b[i].x;
    }
    return 0;
}

int S(cards &a){
    if(a[0].x==14){
        if(a[1].x==5 && a[2].x==4 && a[3].x==3 && a[4].x==2)return 1;
    }
    for(int i=1;i<5;++i)if(a[i].x!=a[i-1].x-1)return 0;
    return 1;
}
int _S(cards &a,cards &b){
    bool same=1;
    for(int i=0;i<5;++i)if(a[i].x!=b[i].x)same=0;
    if(same)return 0;
    if(a[0].x==14 && a[1].x==5)return 1;
    if(b[0].x==14 && b[1].x==5)return 0;
    return b[0].x>a[0].x;
}

int TK(cards &a){
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(a[j].x==i)++c;
        }
        if(c==3)return 1;
    }
    return 0;
}
int _TK(cards &a,cards &b){
    tuple<int,int,int> aa(0,0,0),bb(0,0,0);
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(a[j].x==i)++c;
        }
        if(c==3)get<0>(aa)=i;
        else if(c){
            if(get<2>(aa))get<1>(aa)=i;
            else get<2>(aa)=i;
        }
    }
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(b[j].x==i)++c;
        }
        if(c==3)get<0>(bb)=i;
        else if(c){
            if(get<2>(bb))get<1>(bb)=i;
            else get<2>(bb)=i;
        }
    }
    return bb>aa;
}

int TP(cards &a){
    int cc=0;
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(a[j].x==i)++c;
        }
        if(c==2)++cc;
    }
    return cc==2;
}
int _TP(cards &a,cards &b){
    tuple<int,int,int> aa(0,0,0),bb(0,0,0);
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(a[j].x==i)++c;
        }
        if(c==2){
            if(get<1>(aa))get<0>(aa)=i;
            else get<1>(aa)=i;
        }
        else if(c)get<2>(aa)=i;
    }
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(b[j].x==i)++c;
        }
        if(c==2){
            if(get<1>(bb))get<0>(bb)=i;
            else get<1>(bb)=i;
        }
        else if(c)get<2>(bb)=i;
    }
    return bb>aa;
}

int OP(cards &a){
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(a[j].x==i)++c;
        }
        if(c==2)return 1;
    }
    return 0;
}
int _OP(cards &a,cards &b){
    tuple<int,int,int,int> aa(0,0,0,0),bb(0,0,0,0);
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(a[j].x==i)++c;
        }
        if(c==2)get<0>(aa)=i;
        else if(c){
            if(!get<3>(aa))get<3>(aa)=i;
            else if(!get<2>(aa))get<2>(aa)=i;
            else get<1>(aa)=i;
        }
    }
    for(int i=2;i<=14;++i){
        int c=0;
        for(int j=0;j<5;++j){
            if(b[j].x==i)++c;
        }
        if(c==2)get<0>(bb)=i;
        else if(c){
            if(!get<3>(bb))get<3>(bb)=i;
            else if(!get<2>(bb))get<2>(bb)=i;
            else get<1>(bb)=i;
        }
    }
    return bb>aa;
}

int HC(cards &a,cards &b){
    for(int i=0;i<5;++i){
        if(a[i].x!=b[i].x)return a[i].x<b[i].x;
    }
    return 0;
}

int update(cards a,cards b){ // if b win, rt 1, else 0
    int aa,bb;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    aa=RSF(a); bb=RSF(b);
    if(aa && bb)return 0;
    else if(bb)return 1;
    else if(aa)return 0;
    aa=SF(a); bb=SF(b);
    if(aa && bb)return _SF(a,b);
    else if(bb)return 1;
    else if(aa)return 0;
    aa=FK(a),bb=FK(b);
    if(aa && bb)return _FK(a,b);
    else if(bb)return 1;
    else if(aa)return 0;
    aa=FH(a); bb=FH(b);
    if(aa && bb)return _FH(a,b);
    else if(bb)return 1;
    else if(aa)return 0;
    aa=F(a); bb=F(b);
    if(aa && bb)return _F(a,b);
    else if(bb)return 1;
    else if(aa)return 0;
    aa=S(a); bb=S(b);
    if(aa && bb)return _S(a,b);
    else if(bb)return 1;
    else if(aa)return 0;
    aa=TK(a); bb=TK(b);
    if(aa && bb)return _TK(a,b);
    else if(bb)return 1;
    else if(aa)return 0;
    aa=TP(a); bb=TP(b);
    if(aa && bb)return _TP(a,b);
    else if(bb)return 1;
    else if(aa)return 0;
    aa=OP(a); bb=OP(b);
    if(aa && bb)return _OP(a,b);
    else if(bb)return 1;
    else if(aa)return 0;
    return HC(a,b);
}

cards get_max(cards &to){
    cards mx;
    mx.push_back(to[0]);
    mx.push_back(to[1]);
    mx.push_back(to[2]);
    mx.push_back(to[3]);
    mx.push_back(to[4]);
    for(int i=0;i<7;++i){
        for(int j=i+1;j<7;++j){
            cards nw;
            for(int k=0;k<7;++k){
                if(k==i || k==j)continue;
                nw.push_back(to[k]);
            }
            /* if(i==3 && j==4){
                cout<<"!! update: "<<update(mx,nw)<<endl;
            } */
            if(update(mx,nw))mx=nw;
        }
    }
    return mx;
}

int repeat(cards &a){
    for(int i=0;i<int(a.size());++i){
        for(int j=0;j<i;++j)if(a[i]==a[j])return 1;
    }
    return 0;
}
int repeat(cards &a,cards &b){
    for(card &i:a)for(card &j:b)if(i==j)return 1;
    return 0;
}

int judge(cards &me,cards &op,cards &ta){
    // if(repeat(me,op))return 0;
    // if(repeat(ta,op))return 0;
    // if(repeat(ta,me))return 0;
    // if(repeat(me))return 0;
    // if(repeat(op))return 0;
    // if(repeat(ta))return 0;
    cards allc;
    for(card c:me)allc.push_back(c);
    for(card c:op)allc.push_back(c);
    for(card c:ta)allc.push_back(c);
    if(repeat(allc))return 0;

    ta.push_back(me[0]);
    ta.push_back(me[1]);
    cards max_me=get_max(ta);
    ta.pop_back();
    ta.pop_back();
    ta.push_back(op[0]);
    ta.push_back(op[1]);
    cards max_op=get_max(ta);
    ta.pop_back();
    ta.pop_back();

    /* auto noK=[&]()->int{
        for(auto p:ta)if(p.x==13)return 0;
        return 1;
    }; */
    /* if(!update(max_op,max_me)){
        cout<<"ta    : "; for(auto i:ta)cout<<"("<<i.f<<","<<i.x<<") "; cout<<endl;
        cout<<"max_me: "; for(auto i:max_me)cout<<"("<<i.f<<","<<i.x<<") "; cout<<endl;
        cout<<"max_op: "; for(auto i:max_op)cout<<"("<<i.f<<","<<i.x<<") "; cout<<endl;
        cout<<"no update"<<endl;
    } */
    // cout<<"me win?: "<<update(max_op,max_me)<<endl;
    if(update(max_op,max_me))return 1;
    else return 0;
}

int dfs(cards &me,cards &op,cards &ta){
    if(ta.size()==5u)return judge(me,op,ta);
    card c;
    int r=0;
    for(c.f=1;c.f<=4;++c.f)for(c.x=2;c.x<=14;++c.x){
        ta.push_back(c);
        r+=dfs(me,op,ta);
        ta.pop_back();
    }
    return r;
}

double go(string s_me,string s_op,string s_ta){
    vector<card> me,op,ta;
    parse(s_me,me);
    parse(s_op,op);
    parse(s_ta,ta);
    int wins=dfs(me,op,ta);
    // cout<<wins<<endl;
    return (double)wins/990/2;
}

int main(){
    string s; while(1){
        getline(cin,s);
        if(s[0]=='#')break;
        string t,r; getline(cin,t); getline(cin,r);
        cout<<fixed<<setprecision(20)<<go(s,t,r)<<'\n';
    }
}
