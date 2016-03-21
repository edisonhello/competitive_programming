#include<bits/stdc++.h>

using namespace std;
int jizz=0;
struct dna{
    string a;
    int cnt,srt;
    dna(){
        cnt=0;
        srt=jizz++;
    }
};

bool operator < (const dna &a,const dna &b){
    return a.cnt==b.cnt ? a.cnt<b.cnt : a.srt>b.srt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("in","r",stdin);
    freopen("out","w",stdout);


    int t;cin>>t;

    for(int i=0;i<t;i++){
        int ln,n;
        cin>>ln>>n;

        vector<dna> a;
        for(int j=0;j<n;j++){
            dna tmp;cin>>tmp.a;
            a.push_back(tmp);
        }

        for(int j=0;j<a.size();j++){
            for(int k=0;k<ln;k++){
                for(int l=k+1;l<ln;l++){
                    if(a[j].a[l]<a[j].a[k]){
                        a[j].cnt++;
                    }
                }
            }
        }

        sort(a.begin(),a.end());








        for(int j=0;j<a.size();j++){
            cout<<a[j].a<<endl;
        }
        cout<<endl;
    }
}
