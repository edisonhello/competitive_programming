#include<bits/stdc++.h>

using namespace std;

int rit(){
    int t=0;char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t;
}

int main(){
    vector<pair<int,int> > rd;

    int t=rit();
    for(int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        rd.clear();

        int n=rit();
        for(int i=0;i<n;i++){
            int t1=rit(),t2=rit();
            rd.push_back(make_pair(t1-1,t2-1));
        }

        sort(rd.begin(),rd.end());
        vector<int> res;
        res.resize(n);
        int mx = 0,reci;
        vector<int> gone;
        for(int i=0;i<n;i++){       //printf("in case send to %d\n",i);
            if(res[i]!=0){continue;printf("tag\n");}
            gone.clear();

            int nowat = i;
            while(1){               //printf("now email to %d\n",nowat);
                bool flag= false;
                for(int j=0;j<gone.size();j++){
                    if(gone[j]==nowat){
                        flag = true;
                        break;
                    }
                }       //find loop
                if(flag){
                    for(int j=0;j<gone.size();j++){ //cout<<"jizz "<<j<<endl;
                        if(res[j]==0){
                            res[j] = gone.size();
                        }
                    }
                    break;
                }

                gone.push_back(nowat);
                nowat = rd[nowat].second;
            }
            if(gone.size()>mx){
                mx = gone.size();
                reci = i;
                //if(mx>=n/2)break;
            }
        }

        cout<<reci+1<<endl;
    }
}
