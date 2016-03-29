#include<bits/stdc++.h>

using namespace std;

int main(){
    string a,s,e;cin>>a>>s>>e;
    vector<int> st,ed;
    vector<string> able;    //cout<<"st ";
    while(1){
        int pos;
        if(st.size()==0){
            pos = a.find(s);
        }
        else{
            pos = a.find(s,st.back()+1);
        }

        if(pos == string::npos){
            break;
        }
        else{               //cout<<pos<<" ";
            st.push_back(pos);
        }
    }                       //cout<<endl<<"ed ";
    while(1){
        int pos;
        if(ed.size()==0){
            pos = a.find(e);
        }
        else{
            pos = a.find(e,ed.back()+1);
        }

        if(pos == string::npos){
            break;
        }
        else{               //cout<<pos<<" ";
            ed.push_back(pos);
        }
    }                       //cout<<endl;

    if(st.size()==0 || ed.size()==0){
        printf("0\n");
        return 0;
    }

    for(int i=0;i<st.size();i++){
        for(int j=0;j<ed.size();j++){
            if(st[i]<=ed[j]){        //cout<<"sub "<<st[i]<<" "<<ed[j]+e.length()-1<<" ";
                string t = a;
                t.assign(t,st[i],ed[j]+e.length()-st[i]);   //cout<<t<<endl;
                able.push_back(t);
            }
        }
    }

    sort(able.begin(),able.end());//for(int i=0;i<able.size();i++)//cout<<able[i]<<endl;
    int jizz=0;
    for(int i=1;i<able.size();i++){
        if(able[i] == able[i-1]){
            jizz++;
        }
    }

    printf("%d\n", able.size()-jizz);
}
