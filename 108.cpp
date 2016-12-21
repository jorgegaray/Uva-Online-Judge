
#include <bits/stdc++.h>
using namespace std;
/**
Solution Accepted
108 - Maximum Sum
#TAGS #MATRIX #2D #DP
**/

vector <vector <int> > mtx;
vector <int> vec;
vector <int> arrv;

int main(){
	
	int i,j,k,m;
	int maxpar,maxtotal;
	
	scanf("%d",&m);
	mtx.resize(0);
	mtx.resize(m);

	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			scanf("%d",&k);
			mtx[i].push_back(k);
		}
	}
	maxtotal=mtx[0][0];

	for(i=0;i<m;i++){
		vec.resize(0);
		vec.resize(m,0);
		for(j=i;j<m;j++){
			for(k=0;k<m;k++)
				vec[k]+=mtx[k][j];

			maxpar=0;
			for(k=0;k<m;k++){
				maxpar=max(maxpar+vec[k],0);
				maxtotal=max(maxtotal,maxpar);	
			}		
		}
	}
	printf("%d\n",maxtotal);

	return 0;
}
