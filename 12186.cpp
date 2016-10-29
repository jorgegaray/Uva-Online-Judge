/*****
Another Crisis 12186
tag BFS, SORT
*****/
#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > v(100010);
vector <int>  niv(100010);
vector <int> resp;
double dpor;


int dp(int x){
	if(resp[x]!=-1) return resp[x];
	int i;
	vector <int> ord;
	for(i=0;i<niv[x];i++){
		ord.push_back(dp(v[x][i]));
	}
	double t1=dpor*niv[x];
	int t2=(int)t1;
	double t3=(double)t2;
	if(t1-t3 > 0.000000000000){
		t2++;
	}
	sort(ord.begin(),ord.end());
	int sum=0;
	for(i=0;i<t2;i++)
		sum+=ord[i];
	resp[x]=sum;
	return sum;
}

int main(){


	int n,porc,i,k;

	while(true){
		scanf("%d %d",&n,&porc);
		if(n==0 && porc==0) break;
	
		v.resize(0);
		v.resize(n+10);
		niv.resize(0);
		niv.resize(n+10,0);
		resp.resize(0);
		resp.resize(n+10,1);
		dpor=(double)porc/(double)100;

		for(i=0;i<n;i++){
			scanf("%d",&k);
			niv[k]++;
			v[k].push_back(i+1);
			resp[k]=-1;
		}
		printf("%d\n",dp(0));

	}
	return 0;
}
