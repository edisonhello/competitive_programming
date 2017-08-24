#include<iostream>
#include<vector>
#include<algorithm>
#define All(x) ((x).begin()),((x).end())
#define sz(x) ((int)(x).size())
using namespace std;
struct chess{
  int x;
  bool ab;
  chess():x(0),ab(0){};
  chess(int x,bool ab):x(x),ab(ab){};
};

vector<chess> ru,lu,lr,ud;

inline bool affectRU(int &x,int &y,int &xx,int &yy){return x+y==xx+yy;}
inline bool affectLU(int &x,int &y,int &xx,int &yy){return x-y==xx-yy;}
inline bool affectLR(int &x,int &y,int &xx,int &yy){return x==xx;}
inline bool affectUD(int &x,int &y,int &xx,int &yy){return y==yy;}

bool cmp_x(const chess &a,const chess &b){return a.x<b.x;}

int main() {
  ios_base::sync_with_stdio(0);
  int n;cin>>n;
  int x,y;cin>>x>>y;
  char c;int xi,yi;
  while(n--){
    cin>>c>>xi>>yi;
    if(affectRU(x,y,xi,yi)){
      if(c=='B' || c=='Q'){
        ru.push_back({xi,1});
      }
      else{
        ru.push_back({xi,0});
      }
    }
    else if(affectLU(x,y,xi,yi)){
      if(c=='B' || c=='Q'){
        lu.push_back({xi,1});
      }
      else{
        lu.push_back({xi,0});
      }
    }
    else if(affectLR(x,y,xi,yi)){
      if(c=='R' || c=='Q'){
        lr.push_back({yi,1});
      }
      else{
        lr.push_back({yi,0});
      }
    }
    else if(affectUD(x,y,xi,yi)){
      if(c=='R' || c=='Q'){
        ud.push_back({xi,1});
      }
      else{
        ud.push_back({xi,0});
      }
    }
  }
  ru.push_back({x,0});
  lu.push_back({x,0});
  lr.push_back({y,0});
  ud.push_back({x,0});
  sort(All(ru),cmp_x);
  sort(All(lu),cmp_x);
  sort(All(lr),cmp_x);
  sort(All(ud),cmp_x);
  for(int i=0;i<sz(ru);++i){
    if(ru[i].x==x){
      if(i>0 && ru[i-1].ab){
        cout<<"YES\n";
        return 0;
      }
      if(i+1<sz(ru) && ru[i+1].ab){
        cout<<"YES\n";
        return 0;
      }
    }
  }
  for(int i=0;i<sz(lu);++i){
    if(lu[i].x==x){
      if(i>0 && lu[i-1].ab){
        cout<<"YES\n";
        return 0;
      }
      if(i+1<sz(lu) && lu[i+1].ab){
        cout<<"YES\n";
        return 0;
      }
    }
  }
  for(int i=0;i<sz(lr);++i){
    if(lr[i].x==y){
      if(i>0 && lr[i-1].ab){
        cout<<"YES\n";
        return 0;
      }
      if(i+1<sz(lr) && lr[i+1].ab){
        cout<<"YES\n";
        return 0;
      }
    }
  }
  for(int i=0;i<sz(ud);++i){
    if(ud[i].x==x){
      if(i>0 && ud[i-1].ab){
        cout<<"YES\n";
        return 0;
      }
      if(i+1<sz(ud) && ud[i+1].ab){
        cout<<"YES\n";
        return 0;
      }
    }
  }
  cout<<"NO\n";
  return 0;
}
