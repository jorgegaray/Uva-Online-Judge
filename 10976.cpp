#include <iostream>
#include <cstdio>

using namespace std;
int main(){
	int i,j,l1,l2;
	int x;
	string s1,s2;
	while(1){
		getline(cin,s1);
		getline(cin,s2);
		l1=s1.size();
		l2=s2.size();
		i=0;
		j=0;
		x=0;
		if(s1[0]!=s2[0]){
			printf("no\n");
		}
		else{
			while(1){
				for(;i<l1;i++){
					if(s1[i]==' ')break;
				}
				for(;j<l2;j++){
					if(s2[j]==' ')break;
				}
				if(s1[i+1]!=s2[j+1]){
					x=1;
					break;
				}
			}
			if(x){
				printf("no\n");
			}
			else{
				printf("yes\n");
			}
		}
	
}
	return 0;
}

