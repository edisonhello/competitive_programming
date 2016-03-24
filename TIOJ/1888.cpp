#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
#define X first
#define Y second
#define mid (l+r)/2
using namespace std;
inline ull rit(){
    ull t=0,k=1;char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

int n;
vector<int> wm,ori;
vector<pair<int,int> > sw,cur;

int findtimes(){
    vector<int> cpy = wm;
    vector<pair<int,int> > rec;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(cpy[i]!=i){
            cnt++;
            for(int j=0;j<n;j++){
                if(cpy[j]==i){
                    swap(cpy[i],cpy[j]);
                    rec.push_back(make_pair(i,j));
                    continue;
                }
            }
        }
    }
    cur = rec;
    return cnt;
}

int main(){
    int t=rit();
    while(t--){
        n=rit();
        wm.clear();
        wm.resize(n);
        for(int i=0;i<n;i++){
            wm[i] = rit();
        }
        ori = wm;
        int m = rit();
        for(int i=0;i<m;i++){
            int l=rit(),r=rit();
            sw.push_back(make_pair(min(l,r),max(l,r)));
        }
        swap(wm[sw[0].X],wm[sw[0].Y]);
        //now times means 0;
        int time = findtimes();
        if(time==1){
            goto got_time;
        }
        else{
            for(int i=1;i<sw.size();i++){
                time = findtimes();
                if(time<=i){
                    goto got_time;
                    break;
                }
            }
        }

    got_time:
        string ans = "";
        cout<<time<<endl;
        for(int i=0;i<cur.size();i++){
            swap(ori[sw[i].X],ori[sw[i].Y]);
            for(int j=0;j<n;j++){
                if(cur[i].X==ori[j]){
                    cout<<j<<" ";
                    break;
                }
            }
            for(int j=0;j<n;j++){
                if(cur[i].Y==ori[j]){
                    cout<<j;
                    break;
                }
            }
            cout<<endl;
        }

    }
}
