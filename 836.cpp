#include <bits/stdc++.h>
using namespace std;
/**
Solution Accepted
836 - Largest Submatrix
#TAGS #DP #MATRIX #2D

SIMILAR 108 - Maximum Sum

**/

vector <vector <int> > mtx;
vector <int> vec;

int main(){
	
	int i,j,k,m,w,casos;
	int inx,fnx;
	int maxpar,maxtotal;
	string st;
	scanf("%d",&casos);
	for(w=0;w<casos;w++){
		if(w>0) printf("\n");
	
		cin >> st;
		m=st.size();
		mtx.resize(0);
		mtx.resize(m);
		maxtotal=0;
		for(i=0;i<m;i++){
			if(st[i]=='0')
				mtx[0].push_back(0);
			else
				mtx[0].push_back(1);
		}
		
		for(i=1;i<m;i++){
			cin >> st;
			for(j=0;j<m;j++){
			if(st[j]=='0')
				mtx[i].push_back(0);
			else
				mtx[i].push_back(1);
			}
		}
		for(i=0;i<m;i++){
			vec.resize(0);
			vec.resize(m,0);
			for(j=i;j<m;j++){
				for(k=0;k<m;k++)
					vec[k]+=mtx[k][j];
				
				maxpar=vec[0];
				inx=0;
				fnx=0;
				for(k=1;k<m;k++){
					if(vec[k-1]==vec[k]){
						maxpar+=vec[k];
						fnx=k;
					}
					else{
						if( (j-i+1)*(fnx-inx+1) == maxpar   && maxpar>maxtotal){
							maxtotal=maxpar;
						}
						maxpar=vec[k];
						inx=k;
						fnx=k;
					}
				}
				if((j-i+1)*(fnx-inx+1) == maxpar && maxpar>maxtotal){
					maxtotal=maxpar;
				}			
			}
		}
		printf("%d\n",maxtotal);
	}
	return 0;
}
