#ifndef WEAK
#include"lib1271.h"
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#else
#define PDE1(a) cout<<#a<<" = "<<(a)<<endl
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#endif
#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}

struct node{
    vector<int> pa;
    char ch;
    int len;
    node():ch(0),len(1){}
} *tail[1000009],pool[1000009];
int ptr,_ptr;

void Init(){
	ptr=_ptr=0;
}
node *Init(int &num){
    pool[num].pa.clear();
    ++num;
    return &pool[num-1];
}
void TypeLetter(char c){
    node *&now=tail[++ptr]=Init(_ptr);
    
    now->ch=c;
    now->len=tail[ptr-1]?tail[ptr-1]->len+1:1;
    if(ptr>1){
        now->pa.push_back(ptr-1);
        for(;;){
            if(tail[now->pa.back()]->pa.size()<now->pa.size())break;
            else now->pa.push_back(tail[now->pa.back()]->pa[now->pa.size()-1]);
        }
    }
    PDE4(ptr,now->ch,now->len,now->pa);
}
void UndoCommands(int st){
    ++ptr;
    tail[ptr]=tail[ptr-st-1];
    PDE1(tail[ptr]->ch);
}
char GetLetter(int x){
    ++x;
    int pos=ptr;
    for(int i=25;tail[pos]->len!=x;--i){
        // PDE4(i,x,pos,tail[pos]->len);
        if((tail[pos]->len-x)&(1<<i)){
            // PDE1(i);
            pos=tail[pos]->pa[i];
        }
        if(tail[pos]->len==x)break;
    }
    return tail[pos]->ch;
}

#ifdef WEAK
int main(){
    int cmds;
    start:;
    Init();
    cin>>cmds;
    while(cmds--){
        char ch; cin>>ch;
        if(ch=='T'){
            cin>>ch;
            TypeLetter(ch);
        }
        else if(ch=='U'){
            int udc; cin>>udc;
            UndoCommands(udc);
        }
        else if(ch=='G'){
            int pos; cin>>pos;
            cout<<GetLetter(pos)<<endl;
        }
    }
    cout<<"ctn? ";
    cin>>cmds; if(cmds) goto start;
}
#endif
