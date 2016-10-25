#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
map<string,int> skil;
int GI(string &s){
	auto it=skil.find(s);
	if(it==skil.end()){
		//cout<<"find no "<<s<<", size: "<<skil.size()<<endl;
		skil[s]=skil.size()-1;
	}
	//cout<<"get skill "<<s<<" id : "<<skil[s]<<endl;
	return skil[s];
}
int n;
bool G[35][35];
int lvl[35];
int lrn[35];
struct wntsk{string skn;int skl;};
bool cmp_skn(wntsk a,wntsk b){return GI(a.skn)<GI(b.skn);}
wntsk wants[35];

void dfs(int skid){
	for(int i=0;i<n;++i){
		if(G[skid][i] && !lrn[i]){
			dfs(i);
		}
	}
	lrn[skid]=1;
}

int main(){
	while(cin>>n,n){
		skil.clear();
		memset(G,0,sizeof(G));
		memset(lvl,0,sizeof(lvl));
		// memset(wants,0,sizeof(wants));
		memset(lrn,0,sizeof(lrn));
		for(int i=0;i<n;++i){
			string skname;cin>>skname;
			int reql;cin>>reql;
			lvl[GI(skname)]=reql;
			int pref;cin>>pref;
			for(int j=0;j<pref;++j){
				string presk;cin>>presk;
				G[GI(skname)][GI(presk)]=1;
			}
		}

		//cout<<"processing for wants"<<endl;
		int wantsn;cin>>wantsn;
		for(int i=0;i<wantsn;++i){
			cin>>wants[i].skn>>wants[i].skl;
		}
		//cout<<"sorting"<<endl;
		sort(wants,wants+wantsn,cmp_skn);
		//cout<<"sorted"<<endl;
		for(int i=0;i<wantsn;++i){
			dfs(GI(wants[i].skn));
		}
		for(int i=0;i<wantsn;++i){
			lrn[GI(wants[i].skn)]=max(wants[i].skl,lrn[GI(wants[i].skn)]);
		}
		int pnt=0,nlv=1;
		for(int i=0;i<n;++i){
			//cout<<"lrn["<<i<<"]="<<lrn[i]<<", lvl["<<i<<"]="<<lvl[i]<<endl;
			while(pnt<lrn[i] || nlv<lvl[i]+lrn[i]-1){
				nlv++,pnt++;
			}
			pnt-=lrn[i];
		}
		if(nlv>=100)cout<<"IMPOSSIBLE"<<endl;
		else cout<<nlv<<endl;
	}
}

// struct skill{vector<int> preSkill;int lvlRequire,lvlWant;};
// int n;
// map<string,int> skillMap;
// int getSkillID(string skillName){
// 	//cout<<"get skill name "<<skillName;
// 	auto iter=skillMap.find(skillName);
// 	if(iter==skillMap.end()){
// 		//cout<<" new!";
// 		skillMap[skillName]=skillMap.size()-1;
// 	}
// 	//cout<<" id: "<<skillMap[skillName]<<endl;
// 	return skillMap[skillName];
// }
// skill skills[35];
// void init();
// void read();
// void dfsSkill(int skillID){
// 	if(!skills[skillID].lvlWant)return;
// 	for(int i=0;i<(int)skills[skillID].preSkill.size();++i){
// 		if(!skills[skills[skillID].preSkill[i]].lvlWant)skills[skills[skillID].preSkill[i]].lvlWant=1;
// 		dfsSkill(skills[skillID].preSkill[i]);
// 	}
// }
// void solve(){
// 	int skillsWantn;
// 	cin>>skillsWantn;
// 	for(int i=0;i<skillsWantn;++i){
// 		string wantSkillName;
// 		int wantSkillLvl;
// 		cin>>wantSkillName>>wantSkillLvl;
// 		skills[getSkillID(wantSkillName)].lvlWant=wantSkillLvl;
// 	}
// 	for(int i=0;i<n;++i){
// 		dfsSkill(i);
// 		//cout<<"skill id "<<i<<" lvlWant="<<skills[i].lvlWant<<" ,lvlRequire="<<skills[i].lvlRequire<<endl;
// 	}
// 	int nowLvl=1,skillPnt=0;
// 	for(int i=0;i<n;++i){
// 		while(skillPnt<skills[i].lvlWant || nowLvl<skills[i].lvlRequire+skills[i].lvlWant-1){
// 			nowLvl++;skillPnt++;
// 		}
// 		skillPnt-=skills[i].lvlWant;
// 	}
// 	if(nowLvl>=100)cout<<"IMPOSSIBLE"<<endl;
// 	else cout<<nowLvl<<endl;
// }
// int main(){
// 	while(cin>>n,n){
// 		init();
// 		//cout<<"init done"<<endl;
// 		read();
// 		//cout<<"read done"<<endl;
// 		solve();
// 	}
// }
//
// void init(){
// 	skillMap.clear();
// 	for(int i=0;i<n;++i){
// 		skills[i].preSkill.clear();
// 		skills[i].lvlRequire=0;
// 		skills[i].lvlWant=0;
// 	}
// }
//
// void read(){
// 	for(int i=0;i<n;++i){
// 		string newSkillName;
// 		int newSkillLvlRequire;
// 		int newSkillPreSkilln;
// 		cin>>newSkillName>>newSkillLvlRequire>>newSkillPreSkilln;
// 		skills[getSkillID(newSkillName)].lvlRequire=newSkillLvlRequire;
// 		skills[getSkillID(newSkillName)].preSkill.resize(newSkillPreSkilln);
// 		for(int j=0;j<newSkillPreSkilln;++j){
// 			string preSkillName;
// 			cin>>preSkillName;
// 			skills[getSkillID(newSkillName)].preSkill[j]=getSkillID(preSkillName);
// 		}
// 	}
// }
