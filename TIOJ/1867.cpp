#include<bits/stdc++.h>

using namespace std;

float cross(int x1,int y1,int x2,int y2){
    return x1*y2-y1*x2;
}

int main(){
    string sphere;
    while(getline(cin,sphere) || sphere!="jizz7122"){
        queue<float> input;
        stringstream s;
        while(sphere.length()){
                int i;
            for(    i=0;i<sphere.length();i++){         cout<<"jizz";
                if(sphere[i] == ' '){
                    string cpy = sphere;
                    cpy.assign(cpy,0,i);
                    sphere.assign(sphere,i+1,sphere.length());
                    //cout<<sphere<<endl;
                    float tmp;
                    s << cpy;
                    s >> tmp;
                    input.push(tmp);
                    break;
                }
            }
            if(i == sphere.length())break;
        }
        vector<pair<float,float> > pos;
        while(input.size()){
            float tmp1 = input.front();input.pop();
            float tmp2 = input.front();input.pop();

            pos.push_back(make_pair(tmp1,tmp2));
        }

        float x,y;
        cin>>x>>y;

        bool mn = false;
        for(int i=0;i<pos.size();i++){
            float res ;
            if(i==0)res = cross(pos[pos.size()-1].first-x,pos[pos.size()-1].second-y,pos[0].first-x,pos[0].second-y);
            else res = cross(pos[i-1].first-x,pos[i-1].second-y,pos[i].first-x,pos[i].second-y);
            if(res<0){
                mn = true;
            }
        }
        if(mn){
            cout<<"Stop"<<endl;
        }
        else{
            cout<<"Hit him\n";
        }
    }
}
