#include<string>
#include<ctime>
#include<iostream>
using namespace std;
string f[3];



char fu(){
    int a=rand()%3;
    if(a==0){
        f[0]+='.';
    }
    else if(a==1){
        f[0]+='O';
    }
    else if(a==2){
        f[0]+='X';
    }
    a=rand()%3;
    if(a==0){
        f[0]+='.';
    }
    else if(a==1){
        f[0]+='O';
    }
    else if(a==2){
        f[0]+='X';
    }
    a=rand()%3;
    if(a==0){
        f[0]+='.';
    }
    else if(a==1){
        f[0]+='O';
    }
    else if(a==2){
        f[0]+='X';
    }
    a=rand()%3;
    if(a==0){
        f[1]+='.';
    }
    else if(a==1){
        f[1]+='O';
    }
    else if(a==2){
        f[1]+='X';
    }
    a=rand()%3;
    if(a==0){
        f[1]+='.';
    }
    else if(a==1){
        f[1]+='O';
    }
    else if(a==2){
        f[1]+='X';
    }
    a=rand()%3;
    if(a==0){
        f[1]+='.';
    }
    else if(a==1){
        f[1]+='O';
    }
    else if(a==2){
        f[1]+='X';
    }
    a=rand()%3;
    if(a==0){
        f[2]+='.';
    }
    else if(a==1){
        f[2]+='O';
    }
    else if(a==2){
        f[2]+='X';
    }
    a=rand()%3;
    if(a==0){
        f[2]+='.';
    }
    else if(a==1){
        f[2]+='O';
    }
    else if(a==2){
        f[2]+='X';
    }
    a=rand()%3;
    if(a==0){
        f[2]+='.';
    }
    else if(a==1){
        f[2]+='O';
    }
    else if(a==2){
        f[2]+='X';
    }
}

int main(){


    srand(time(NULL));
    bool can=true;

while(1){
        can = true;
    f[0]=f[1]=f[2]="";
    fu();
    int o=0,x=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(f[i][j]=='O'){
                o++;
            }
            else if(f[i][j]=='X'){
                x++;
            }
            else if(f[i][j]!='.'){
                can = false;
            }
        }
    }

    int ol1=0,ol2=0,xl1=0,xl2=0;
    for(int i=0;i<3;i++){
        if(f[i][0]=='O'&&f[i][1]=='O'&&f[i][2]=='O'){
            ol1++;
        }
        if(f[0][i]=='O'&&f[1][i]=='O'&&f[2][i]=='O'){
            ol2++;
        }
        if(f[i][0]=='X'&&f[i][1]=='X'&&f[i][2]=='X'){
            xl1++;
        }
        if(f[0][i]=='X'&&f[1][i]=='X'&&f[2][i]=='X'){
            xl2++;
        }
    }

    int w=0;
    if(ol1+ol2 && xl1+xl2){
        can = false;
    }
    else if(ol1>1 || ol2>1 || xl1>1 ||xl2>1){
        can = false;
    }
    else{
        if(ol1+ol2){
            w=1;
        }
        else if(xl1+xl2){
            w=2;
        }
    }


    if((o==x && w!=1) || (o==x+1 && w!=2)){
        ;
    }
    else{
        can = false;
    }

    cout<<f[0]<<endl<<f[1]<<endl<<f[2]<<endl<<endl;
    if(can){
        char a;
        // cin>>a;
        system("PAUSE");
    }
}
}

