/**
624 - CD
**/
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
long long int minutos,pistas,suma;
vector <int> tracks(21);
vector<int> finalcamino;
 
void dfs_binario(vector<int> camino, int acumulado, int i) {
	if(i == pistas){
		if(acumulado > suma || (acumulado==suma && camino.size()> finalcamino.size())){
			suma=acumulado;
			finalcamino=camino;
		}
		return;	
	} 
	else{
		dfs_binario(camino,acumulado,i+1);

		if(acumulado + tracks[i]<= minutos){
    		acumulado += tracks[i];
    		camino.push_back(tracks[i]);
			dfs_binario(camino,acumulado, i+1);
		}
		else{
			if(acumulado > suma || (acumulado==suma && camino.size()> finalcamino.size())){
				suma=acumulado;
				finalcamino=camino;
			}
		}
    }
    return;
}

int main(){

	int i,l;

	while(scanf("%lld",&minutos) != EOF){

		scanf("%lld",&pistas);		
		for(i=0; i < pistas;i++){
			scanf("%d",&tracks[i]);
		}
		vector <int> p;
		suma=0;
		dfs_binario(p,0,0);
		l=finalcamino.size();
		for(i=0; i <l ; i++){
			printf("%d ",finalcamino[i]);
		}
		printf("sum:%lld\n", suma);
	}
	return 0;
}

