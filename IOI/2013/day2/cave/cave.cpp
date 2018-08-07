#include "grader.h"
#include<bits/stdc++.h>

#define try_comb tryCombination

using namespace std;

/*
int tryCombination(int s[]);

void answer(int s[],int d[]);
*/

int cur_comb[5005],match_to[5005];

void exploreCave(int n){
    memset(match_to,0xff,sizeof(match_to));
    for(int i=0;i<n;++i){
        vector<int> unknown_pos;
        for(int z=0;z<n;++z)if(match_to[z]==-1)unknown_pos.push_back(z);
        for(int i:unknown_pos)cur_comb[i]=0;
        
        int L=0,R=unknown_pos.size()-1;
        int first_open=try_comb(cur_comb);
        int cur_close=(first_open!=-1 && first_open<=i);
        
        int last_ans=!cur_close;
        while(R>L){
            int M=(L+R)>>1;
            for(int i=L;i<=M;++i)cur_comb[unknown_pos[i]]^=1;
            int first_open=try_comb(cur_comb);
            int cur_close=(first_open!=-1 && first_open<=i);
            if(last_ans==cur_close)R=M;
            else L=M+1;
            last_ans=!cur_close;
        }
        // cout<<"i: "<<i<<" , L: "<<L<<endl;
        match_to[unknown_pos[L]]=i;
        if(!last_ans)cur_comb[unknown_pos[L]]^=1;
    }
    answer(cur_comb,match_to);
}
