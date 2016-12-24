#include <bits/stdc++.h>
using namespace std;
/***
12468 Zapping
***/
int main(){
    int a,b;
    while(true){
        scanf("%d %d",&a,&b);
        if(a==-1 || b==-1) break;
        else if(a==b) printf("0\n");
        else if(a<b) printf("%d\n",min(b-a, a+1+99-b));
        else printf("%d\n",min(a-b, b+1+99-a));
    }
    return 0;
}
