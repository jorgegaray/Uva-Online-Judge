#include <bits/stdc++.h>
using namespace std;

int main(){

	map <double,int> mp;
	string st;
	int i,m;
	int n,l,c;
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