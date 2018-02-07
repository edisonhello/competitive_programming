#include<bits/stdc++.h>
using namespace std;

struct Row{
    string row;
    bool notFull(){
        for(char j:row)if(j=='-')return 1;
        return 0;
    }
    int emptys(){
        int cnt=0;
        for(char j:row)if(j=='-')++cnt;
        return cnt;
    }
    int getCol(int L,int R){
        int LR=(L<R?1:0);
        if(row[4]=='-' && row[6]=='-')return LR?6:4;
        if(row[4]=='-')return 4;
        if(row[6]=='-')return 6;
        if(row[2]=='-' && row[8]=='-')return LR?8:2;
        if(row[2]=='-')return 2;
        if(row[8]=='-')return 8;
        if(row[0]=='-' && row[10]=='-')return LR?10:0;
        if(row[0]=='-')return 0;
        if(row[10]=='-')return 10;
        if(row[5]=='-')return 5;
        if(row[1]=='-' && row[9]=='-')return LR?9:1;
        if(row[1]=='-')return 1;
        if(row[9]=='-')return 9;
        exit(12345);
    }
} row[66];

// string mp[50];

int main(){
    int r,n; cin>>r>>n;
    for(int i=0;i<r+3;++i)cin>>row[i].row;
    for(char in='a',cnt=0;cnt<n;++in,++cnt){
        // cout<<"Let's put "<<in<<endl;
        vector<int> rowConsider;
        if(row[1].notFull())rowConsider.push_back(1);
        if(row[r/2+2].notFull())rowConsider.push_back(r/2+2);
        if(rowConsider.empty())for(int i=0;i<r+3;++i)if(row[i].notFull())rowConsider.push_back(i);
        sort(rowConsider.begin(),rowConsider.end(),[](const int &a,const int &b){
            return row[a].emptys()>row[b].emptys();
        });
        // for(int i:rowConsider)cout<<i<<" "; cout<<endl;
        // for(int i:rowConsider)cout<<row[i].emptys()<<" "; cout<<endl;
        vector<int> tmp;
        for(int i:rowConsider){
            if(row[i].emptys()==row[rowConsider[0]].emptys())tmp.push_back(i);
            else break;
        }
        rowConsider=tmp;
        // for(int i:rowConsider)cout<<i<<" "; cout<<endl;
        tmp.clear();
        sort(rowConsider.begin(),rowConsider.end(),[&](const int &a,const int &b){
            return min(abs(a-0),min(abs(a-r/2-1),abs(a-r-2)))<min(abs(b-0),min(abs(b-r/2-1),abs(b-r-2)));
        });
        // for(int i:rowConsider)cout<<i<<" "; cout<<endl;
        // for(int i:rowConsider)cout<<min(abs(i-0),min(abs(i-r/2-1),abs(i-r-2)))<<" "; cout<<endl;
        for(int i:rowConsider){
            if(min(abs(i-0),min(abs(i-r/2-1),abs(i-r-2)))==min(abs(rowConsider[0]-0),min(abs(rowConsider[0]-r/2-1),abs(rowConsider[0]-r-2))))tmp.push_back(i);
            else break;
        }
        rowConsider=tmp;
        // for(int i:rowConsider)cout<<i<<" "; cout<<endl;
        sort(rowConsider.begin(),rowConsider.end());

        int rowNumber=rowConsider[0];
        int L=0,R=0;
        for(int i=1;i<r+3;++i){
            for(int j=0;j<11;++j){
                if(j<5 && row[i].row[j]=='-')++L;
                if(j>5 && row[i].row[j]=='-')++R;
            }
        }
        // cout<<L<<" "<<R<<endl;
        int colNumber=row[rowNumber].getCol(L,R);
        row[rowNumber].row[colNumber]=in;
    }
    for(int i=0;i<r+3;++i)cout<<row[i].row<<endl;
}
