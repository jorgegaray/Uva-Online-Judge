/***
Feynman 12149
cuadrado 1 = 1*1
         2 = 1*1 + 2*2
	 3 = 1*1 + 2*2 + 3*3
	 4 = 1*1 + 2*2 + 3*3 + 4*4
	 .....
****/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int i, n;
	vector <int> v(101);
	for(i=0;i<101;i++){
		v[i]=i*i;
	}
	for(i=1;i<101;i++){
		v[i]=v[i]+v[i-1];
	}

	while(true){
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",v[n]);
	}

	return 0;
}
