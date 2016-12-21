#include <bits/stdc++.h>
using namespace std;
/**
Solution Accepted
869 - Airline Comparison
#TAGS #DFS #DP
**/
vector < vector < int> > listAdj;
vector <int> vec;
vector < vector < int> > respA;
vector < vector < int> > respB;
int total;

vector <int> DFS_vecA(int v){
	if(vec[v]==1) return respA[v];
	vec[v]=1;
	vector <int> vv;
	vector <int> aux;
	vector <int> ok(total,0);
	int j,i,l=listAdj[v].size();

	for(i=0;i<l;i++){
		if(ok[listAdj[v][i]]==0){
			aux=DFS_vecA(listAdj[v][i]);
			vv.push_back(listAdj[v][i]);
			ok[listAdj[v][i]]=1;
			for(j=0;j<aux.size();j++){
				vv.push_back(aux[j]);
				ok[aux[j]]=1;
			}
		}
	}
	respA[v]=vv;
	return vv;
}

vector <int> DFS_vecB(int v){
	if(vec[v]==1) return respB[v];
	vec[v]=1;
	vector <int> vv;
	vector <int> aux;
	vector <int> ok(total,0);
	int j,i,l=listAdj[v].size();

	for(i=0;i<l;i++){
		if(ok[listAdj[v][i]]==0){
			aux=DFS_vecB(listAdj[v][i]);
			vv.push_back(listAdj[v][i]);
			ok[listAdj[v][i]]=1;
			for(j=0;j<aux.size();j++){
				vv.push_back(aux[j]);
				ok[aux[j]]=1;
			}
		}
	}
	respB[v]=vv;
	return vv;
}

int check_equivalent(){
	int i,j;
	vector <int> ok1(total,0);
	vector <int> ok2(total,0);

	for(i=0;i<total;i++){
		ok1.resize(0);
		ok1.resize(total,0);
		ok2.resize(0);
		ok2.resize(total,0);
		for(j=0;j<respA[i].size();j++)
			ok1[respA[i][j]]=1;
		for(j=0;j<respB[i].size();j++)
			ok2[respB[i][j]]=1;
		for(j=0; j<total;j++)
			if(ok1[j]!=ok2[j]) return 0;

	}
	return 1;
}

int main(){

	int cases,N,M,i,j,salir;
	set < string > ss;
	map <string,int > m;
	string s1, s2;
	int count=0;
	scanf("%d",&cases);

	for(j=0;j<cases;j++){
		if(j>0) printf("\n");
		scanf("%d",&N);
		listAdj.resize(0);
		listAdj.resize(2*N+10);
		ss.clear();
		m.clear();
		count=0;
		salir=0;
		for(i=0;i<N;i++){
			cin >> s1 >> s2;
			if(ss.insert(s1).second){
				m[s1]=count;
				count++;
			}
			if(ss.insert(s2).second){
				m[s2]=count;
				count++;
			}
			listAdj[m[s1]].push_back(m[s2]);
		}
		vec.resize(0);
		vec.resize(count,0);
		respA.resize(0);
		respA.resize(count+10);
		total=count;
		for(i=0;i<count;i++){
			if(vec[i]==0){
				DFS_vecA(i);
			}
		}

		listAdj.resize(0);
		listAdj.resize(2*N+10);
		scanf("%d",&M);
		for(i=0;i<M;i++){
			cin >> s1 >> s2;
			if(ss.insert(s1).second || ss.insert(s2).second){
				salir=1;
			}
			listAdj[m[s1]].push_back(m[s2]);			
		}
		if(salir==1){
			printf("NO\n");
		}
		else{
			vec.resize(0);
			vec.resize(count,0);
			respB.resize(0);
			respB.resize(count+10);
			for(i=0;i<count;i++){
				if(vec[i]==0){
					DFS_vecB(i);
				}
			}
			if(check_equivalent()){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}	
	}
	return 0;
}
