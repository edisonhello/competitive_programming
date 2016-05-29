#include<bits/stdc++.h>
using namespace std;


inline int rit(){
    int t=0,k=1;char c;
    do{
        c = getchar();
        if(c=='-'){
            k=-1;
        }
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c = getchar();
    }while(c<='9'&&c>='0');
    return t*k;
}

int main(){
    int len=rit(),ch=rit();
    string s;cin>>s;
    vector<int> rec;

    int i,j;
    for(i=0;i<len;i=j){
        int cnt=1;
        for(j=i+1;s[i]==s[j];j++){
            cnt++;
        }
        rec.push_back(cnt);
        // cout<<cnt;
    }
    // cout<<endl;

    int mx=-9898988,now=0,l=0,r=0,lftk=ch,sz=rec.size();
    for(;r<sz && l<sz;){
        if(lftk>=0){
            // r==sz-1?break:0;
            now+= rec[r++];
            // int nxwall=rec[r++];
            // int canbrk = lftk>nxwall ? nxwall : lftk;
            // lftk-=
            int trecr = r!=sz-1?rec[r++]:0;
            int reclftk = lftk;
            lftk-=trecr;
            now += lftk<0 ? reclftk : trecr;
            mx = max(mx,now);
        }
        else{
            // l==sz-1?break:0;
            now-= l!=sz-1?rec[l++]:0;
            int t= l!=sz-1?rec[l++]:0;
            lftk+=t;
            now-=t;
        }
        // cout<<l<<" "<<r<<" "<<lftk<<" "<<now<<endl;;
    }
    int ans1=mx;

    for(int i=0;i<sz/2;i++){
        swap(rec[i],rec[sz-i-1]);
    }
    // cout<<endl;

    mx=-9898988,now=0,l=0,r=0,lftk=ch,sz=rec.size();
    for(;r<sz && l<sz;){
       if(lftk>=0){
        //    r==sz-1?r++:0;
           now+= rec[r++];
           // int nxwall=rec[r++];
           // int canbrk = lftk>nxwall ? nxwall : lftk;
           // lftk-=
           int trecr = r!=sz-1?rec[r++]:0;
           int reclftk = lftk;
           lftk-=trecr;
           now += lftk<0 ? reclftk : trecr;
           mx = max(mx,now);
       }
       else{
        //    l==sz-1?l++:0;
           now-= l!=sz-1?rec[l++]:0;
           int t= l!=sz-1?rec[l++]:0;
           lftk+=t;
           now-=t;
       }
    //    cout<<l<<" "<<r<<" "<<lftk<<" "<<now<<endl;;
    }

    int ans2=mx;
    cout<<max(ans1,ans2)<<endl;
}
