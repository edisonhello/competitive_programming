#include<bits/stdc++.h>
using namespace std;
string mp[10];
bool gone[10][10];
int n,gotshort,totshort,thistype,tottype=1;
struct _6{
    int a,b,c,d,f;
    char e;
};
queue<_6>goq;
void go(int nx,int ny,int px,int py,char dis,int len){
    printf("come to %d %d dist %d %d\n",nx,ny,px,py);
    if(gotshort){
        if(dis>gotshort){
            return;
        }
    }
    gone[nx][ny] = 1;
    if(nx==px && ny==py){
        if(gotshort){
            if(len>gotshort){
                return;
            }
            else if(len==gotshort){
                thistype++;
            }
            else{
                thistype=0;
                gotshort=len;
            }
        }
        else{
            gotshort = len;
            thistype =   1;
        }
        goq.pop();
        return;
    }

    //cout<<mp[nx][ny]<<mp[nx+1][ny]<<endl<<mp[nx][ny+1]<<mp[nx+1][ny+1]<<endl;

    _6 t;
    if(nx!=0 && (mp[nx-1][ny]=='.' || mp[nx-1][ny]==dis) && !(gone[nx-1][ny])){
        t.a=nx-1;
        t.b=ny;
        t.c=px;
        t.d=py;
        t.e=dis;
        t.f=len+1;
        goq.push(t);
    }
    if(ny!=0 && (mp[nx][ny-1]=='.' || mp[nx][ny-1]==dis) && !(gone[nx][ny-1])){
        t.a=nx;
        t.b=ny-1;
        t.c=px;
        t.d=py;
        t.e=dis;
        t.f=len+1;
        goq.push(t);
    }
    if(nx<n-1 && (mp[nx+1][ny]=='.' || mp[nx+1][ny]==dis) && !(gone[nx+1][ny])){
        t.a=nx+1;
        t.b=ny;
        t.c=px;
        t.d=py;
        t.e=dis;
        t.f=len+1;
        goq.push(t);
    }//cout<<(ny<n-1 && (mp[nx][ny+1]=='.' || mp[nx][ny+1]==dis))<<endl;
    if(ny<n-1 && (mp[nx][ny+1]=='.' || mp[nx][ny+1]==dis) && !(gone[nx][ny+1])){
        t.a=nx;
        t.b=ny+1;
        t.c=px;     cout<<"jizz"<<endl;
        t.d=py;
        t.e=dis;
        t.f=len+1;
        goq.push(t);        //cout<<goq.size()<<endl;
    }
    goq.pop();
}


int main(){
    int t=0;
    while(cin>>n && n && ++t){
        cout<<"Case "<<t<<": ";
        for(int i=0;i<n;i++){
            cin>>mp[i];
        }

        int posx[26],posy[26];
        memset(posx,0,sizeof(posx));
        memset(posy,0,sizeof(posy));
        for(int i=0;i<n;i++){
            posy[0] = mp[i].find('A');
            if(posy[0]!=string::npos){
                posx[0]=i;
                break;
            }
        }
        bool jizz = 0;
        for(int i=1;!(jizz);i++){
            //finding
            gotshort=0;
            thistype=0;
            memset(gone,0,sizeof(gone));
            bool fd=false;
            for(int a=0;i<n;a++){
                posy[i] = mp[a].find(i+65);
                if( posy[i] !=string::npos){
                    fd=true;
                    posx[i] = a;
                    break;
                }
            }
            if(!fd){
                break;
            }
            else if(fd){
                _6 _;
                _.a=posx[i-1];
                _.b=posy[i-1];
                _.c=posx[i];
                _.d=posy[i];
                _.e=i+65;
                _.f=0;
                goq.push(_);
                while(goq.size()>0){
                    go(goq.front().a,goq.front().b,goq.front().c,goq.front().d,goq.front().e,goq.front().f);
                }
            }
            tottype*=thistype;
            if(tottype==0){
                cout<<"Impossible"<<endl;
                jizz = 1;
                break;
            }
            totshort+=gotshort;
            mp[posx[i]][posy[i]]='.';
            gotshort=0;
        }
        if(!jizz){
            cout<<totshort<<" "<<tottype<<endl;
        }
    }
}
