#include<stdio.h>
int main(){
	
	int a,b,c,x,y;
	int max = 0;
	scanf("%d %d %d", &a,&b,&c);
	
	while(a!=0 && b!=0 && c!=0){
		if(a>b){
			max = a;
		
			if(c>a){
				max = c;
				x=a, y=b;
			}
			x=b,y=c;
		}
	
		else if(b>c){
			max = b, x=a, y=c;
		}
	
		else max = c, x=a, y=b;
	
		if((max * max) == (x * x) + (y * y)){
			printf("right\n");
		}
		else printf("wrong\n");
		
		scanf("%d %d %d", &a,&b,&c);
	}

	return 0;
}