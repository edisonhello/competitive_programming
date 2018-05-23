#include<bits/stdc++.h>
using namespace std;

struct poker{
    vector<int> card;
    poker(int a,int b,int c,int d,int e){
        card.push_back(a);
        card.push_back(b);
        card.push_back(c);
        card.push_back(d);
        card.push_back(e);
    }
    void sort_by_number(){
        sort(card.begin(),card.end(),[](const int &a,const int &b)->bool{if(a==1)return 0; if(b==1)return 1; return a<b;});
    }
    void output(){
        char mp[]={'0','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
        for(int i=0;i<5;++i)cout<<mp[card[i]]<<" \n"[i==4];
    }
    bool is_royal(){
        return card[0]==10 && card[1]==11 && card[2]==12 && card[3]==13 && card[4]==1;
    }
    bool is_straight(){
        // output();
        sort(card.begin(),card.end());
        bool rt=1;
        for(int i=1;i<5;++i)if(card[i]-card[0]!=i)rt=0;
        sort_by_number();
        // cout<<"is straight: "<<rt<<endl;
        return rt;
    }
    int getmin(){
        return *min_element(card.begin(),card.end());
    }
    bool is_four(){ return get4(); }
    int get4(){
        int cnt[14]={0};
        for(int i:card)++cnt[i];
        int rt=0;
        for(int i=1;i<=13;++i)if(cnt[i]>=4)rt=i;
        return rt;
    }
    bool is_three(){
        return get3();
    }
    int get3(){
        int cnt[14]={0};
        for(int i:card)++cnt[i];
        int rt=0;
        for(int i=1;i<=13;++i)if(cnt[i]>=3)rt=i;
        return rt;
    }
    bool is_full(){
        int z=get3();
        if(!z)return 0;
        int cnt[14]={0};
        for(int i:card)if(i!=z)++cnt[i];
        bool is=0;
        for(int i=1;i<=13;++i)if(cnt[i]==2)is=1;
        return is;
    }
};

int main(){
    int t; cin>>t; while(t--){
        int s; cin>>s;
        vector<poker> v;
        for(int i=1;i<=13;++i){
            for(int j=i;j<=13;++j){
                for(int k=j;k<=13;++k){
                    for(int l=k;l<=13;++l){
                        int m=s-i-j-k-l;
                        if(m<1 || m>13)continue;
                        if(m<l)continue;
                        int cnt[14]={0};
                        ++cnt[i]; ++cnt[j]; ++cnt[k]; ++cnt[l]; ++cnt[m];
                        bool ok=1;
                        for(int i=1;i<=13;++i)if(cnt[i]>4)ok=0;
                        if(!ok)continue;
                        v.emplace_back(i,j,k,l,m);
                        // cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<endl;
                        v.back().sort_by_number();
                    }
                }
            }
        }
        poker mx=*max_element(v.begin(),v.end(),[](poker &a,poker &b)->bool{
            /* cout<<"compareing ";
            a.output();
            cout<<" and ";
            b.output(); */
            if(a.is_royal())return 0;
            if(b.is_royal())return 1;
            if(a.is_straight() && b.is_straight())return a.getmin()<b.getmin();
            if(a.is_straight())return 0;
            if(b.is_straight())return 1;
            if(a.is_four() && b.is_four()){
                int a4=a.get4();
                int b4=b.get4();
                if(a4==1)return 0;
                if(b4==1)return 1;
                return a4<b4;
            }
            if(a.is_four())return 0;
            if(b.is_four())return 1;
            if(a.is_full() && b.is_full()){
                int a3=a.get3();
                int b3=b.get3();
                if(a3==1)return 0;
                if(b3==1)return 1;
                return a3<b3;
            }
            if(a.is_full())return 0;
            if(b.is_full())return 1;
            if(a.is_three() && b.is_three()){
                int a3=a.get3();
                int b3=b.get3();
                if(a3==1)return 0;
                if(b3==1)return 1;
                return a3<b3;
            }
            if(a.is_three())return 0;
            return 1;
        });
        mx.sort_by_number();
        mx.output();
    }
}
