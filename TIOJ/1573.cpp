#include<bits/stdc++.h>
using namespace std;
int mp[5][5];
bool cur[5][5];
int rgt;
int zrx,zry;
// vector<int[4][4]> v;

void P(){
    cout<<"map:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int iddfs(int zx,int zy,int left,int cs){
    // cout<<"left:"<<left<<", zx="<<zx<<", zy="<<zy<<endl;
    // P();
    if(rgt==15)return left;
    if(left==0)return -1;
    if(zx>0 && cs!=2){
        bool cs1=0,cs2=0;
        if(cur[zx-1][zy]){cur[zx-1][zy]=0;rgt--;cs1=1;}
        else if(mp[zx-1][zy]==zx*4+zy+1){cur[zx][zy]=1;rgt++;cs2=1;}
        swap(mp[zx][zy],mp[zx-1][zy]);
        int res = iddfs(zx-1,zy,left-1,1);
        if(res!=-1)return res;
        swap(mp[zx][zy],mp[zx-1][zy]);
        if(cs1){cur[zx-1][zy]=1;rgt++;}
        else if(cs2){cur[zx][zy]=0;rgt--;}
    }
    if(zx<3 && cs!=1){
        bool cs1=0,cs2=0;
        if(cur[zx+1][zy]){cur[zx+1][zy]=0;rgt--;cs1=1;}
        else if(mp[zx+1][zy]==zx*4+zy+1){cur[zx][zy]=1;rgt++;cs2=1;}
        swap(mp[zx][zy],mp[zx+1][zy]);
        int res = iddfs(zx+1,zy,left-1,2);
        if(res!=-1)return res;
        swap(mp[zx][zy],mp[zx+1][zy]);
        if(cs1){cur[zx+1][zy]=1;rgt++;}
        else if(cs2){cur[zx][zy]=0;rgt--;}
    }
    if(zy>0 && cs!=4){
        bool cs1=0,cs2=0;
        if(cur[zx][zy-1]){cur[zx][zy-1]=0;rgt--;cs1=1;}
        else if(mp[zx][zy-1]==zx*4+zy+1){cur[zx][zy]=1;rgt++;cs2=1;}
        swap(mp[zx][zy],mp[zx][zy-1]);
        int res = iddfs(zx,zy-1,left-1,3);
        if(res!=-1)return res;
        swap(mp[zx][zy],mp[zx][zy-1]);
        if(cs1){cur[zx][zy-1]=1;rgt++;}
        else if(cs2){cur[zx][zy]=0;rgt--;}
    }
    if(zy<3 && cs!=3){
        bool cs1=0,cs2=0;
        if(cur[zx][zy+1]){cur[zx][zy+1]=0;rgt--;cs1=1;}
        else if(mp[zx][zy+1]==zx*4+zy+1){cur[zx][zy]=1;rgt++;cs2=1;}
        swap(mp[zx][zy],mp[zx][zy+1]);
        int res = iddfs(zx,zy+1,left-1,4);
        if(res!=-1)return res;
        swap(mp[zx][zy],mp[zx][zy+1]);
        if(cs1){cur[zx][zy+1]=1;rgt++;}
        else if(cs2){cur[zx][zy]=0;rgt--;}
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>mp[i][j];
            if(mp[i][j]==0){
                zrx=i,zry=j;
            }
            if(mp[i][j]==i*4+j+1){
                cur[i][j]=1;
                rgt++;
            }
        }
    }

    for(int i=1;i<26;i++){
        // cout<<"iidfs for i="<<i<<endl;
        int res = iddfs(zrx,zry,i,0);
        if(res!=-1){
            cout<<i-res<<'\n';
            return 0;
        }
    }
    cout<<"-1\n";
}
