/****
Jingle Composing 12195
**/
#include <bits/stdc++.h>
using namespace std;

int main(){

	string st;
	int i, l;
	double cc;
	double f[200];
	int resp;
	f['W']=1.000000;
	f['H']=0.500000;
	f['Q']=0.250000;
	f['E']=0.125000;
	f['S']=0.062500;
	f['T']=0.031250;
	f['X']=0.015625;
	while(cin>> st){
		if(st=="*")break;
		l=st.size();
		cc=0.0;
		resp=0;
		for(i=1;i<l;i++){
			if(st[i]=='/'){
				if(cc==1.000000){
					resp++;
				}
				cc=0.000000;
			}
			else{
				cc+=f[st[i]];
			}
		}
		printf("%d\n",resp);
	}

	return 0;
}
