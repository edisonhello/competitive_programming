#include<bits/stdc++.h>
using namespace std;

map<string,int> m;
void init(){
	int cnt=1;
	for(int a=0;a<26;a++){
		string s;
		s.push_back(a+'a');
		m[s]=cnt;
		cnt++;
	}
	for(int a=0;a<26;a++){
		for(int b=a+1;b<26;b++){
			string s;
			s.push_back(a+'a');s.push_back(b+'a');
			m[s]=cnt;
			cnt++;
		}
	}
	for(int a=0;a<26;a++){
		for(int b=a+1;b<26;b++){
			for(int c=b+1;c<26;c++){
				string s;
				s.push_back(a+'a');s.push_back(b+'a');s.push_back(c+'a');
				m[s]=cnt;
				cnt++;
			}
		}
	}
	for(int a=0;a<26;a++){
		for(int b=a+1;b<26;b++){
			for(int c=b+1;c<26;c++){
				for(int d=c+1;d<26;d++){
					string s;
					s.push_back(a+'a');s.push_back(b+'a');s.push_back(c+'a');s.push_back(d+'a');
					m[s]=cnt;
					cnt++;
				}
			}
		}
	}
	for(int a=0;a<26;a++){
		for(int b=a+1;b<26;b++){
			for(int c=b+1;c<26;c++){
				for(int d=c+1;d<26;d++){
					for(int e=d+1;e<26;e++){
						string s;
						s.push_back(a+'a');s.push_back(b+'a');s.push_back(c+'a');s.push_back(d+'a');s.push_back(e+'a');
						m[s]=cnt;
						cnt++;
					}
				}
			}
		}
	}
}

int main(){
    init();
    string s;
    while(cin>>s){
        int no=0;
        for(int i=1;i<s.length();i++){
            if(s[i]<=s[i-1]){
                cout<<0<<endl;
                no=1;
                break;
            }
        }
        if(!no){
            cout<<m[s]<<endl;
        }
    }
}
