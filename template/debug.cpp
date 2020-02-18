#ifndef WEAK_DEBUG
#define WEAK_DEBUG
#ifdef WEAK

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__,9,8,7,6,5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define PDE1(a) cout<<#a<<" = "<<(a)<<endl
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#define PDE6(a,b,c,d,e,f) cout<<#a<<" = "<<(a)<<" , ", PDE5(b,c,d,e,f)
#define PDE7(a,b,c,d,e,f,g) cout<<#a<<" = "<<(a)<<" , ", PDE6(b,c,d,e,f,g)
#define PDE8(a,b,c,d,e,f,g,h) cout<<#a<<" = "<<(a)<<" , ", PDE7(b,c,d,e,f,g,h)
#define PDE9(a,b,c,d,e,f,g,h,i) cout<<#a<<" = "<<(a)<<" , ", PDE8(b,c,d,e,f,g,h,i)
#define PDE(...) macro_dispatcher(PDE, __VA_ARGS__)(__VA_ARGS__)

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.first<<","<<p.second<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB,typename TC> ostream& operator<<(ostream &ostm, const map<TA,TB,TC> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB,typename TC> ostream& operator<<(ostream &ostm, const unordered_map<TA,TB,TC> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const multiset<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename TA,typename TB,typename TC> ostream& operator<<(ostream &ostm,const priority_queue<TA,TB,TC> &inp){priority_queue<TA,TB,TC> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}
// ostream& operator<<(ostream &ostm,const __int128 &val){if(!val){ostm<<"0"; return ostm;} bool mns=0; __int128 cpy=(val<0?mns=1,-val:val); stack<char> st; while(cpy)st.push(cpy%10+'0'),cpy/=10; if(mns)st.push('-'); while(st.size())ostm<<st.top(),st.pop(); return ostm;}

#endif
#endif
