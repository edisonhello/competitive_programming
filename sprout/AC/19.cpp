#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
#include<stack>
using namespace std;

int main()
{
    stack<int> station;
    vector<int> wantlist;

    int t;cin>>t;
    for(int time = 1;time <= t; time++){
        int tot;cin>>tot;
        wantlist.clear();
        for(;station.size();){
            station.pop();
        }
        for(int inputing = 1;inputing <= tot;inputing++){
            int in;cin>>in;
            wantlist.push_back(in);
        }
        int got = 0;

        bool ifno1 = true,
             ifno2 = true;
        for(int now = 1;now <= tot && got < tot;){
            ifno1 = true;
            ifno2 = true;
            //cout<<"now come "<<now<<endl;
            if(now == wantlist.at(got)){
                //cout<<"now == want: "<<now<<endl;
                got++;
                ifno1 = false;
            }
            while(station.size() != 0 && station.top() == wantlist.at(got)){
                //cout<<"station == want "<<wantlist.at(got)<<endl;
                got++;
                station.pop();
                ifno2 = false;
            }
            if(ifno1 && ifno2){
                //cout<<"push now: "<<now<<endl;
                station.push(now);
            }
            now++;
        }
        if(station.size() == 0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
