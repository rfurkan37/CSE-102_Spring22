#include <stdio.h>


int main(){
	int top = 0;
	
	int i = 0;
	for (int i = 0;i<=20;i++){
		int sayi;
		printf("sayi girin:");
		scanf("%d",&sayi);
		top = sayi + top;
		
		
	}
	printf("sayilarin toplami sudur=%d",top);
	
	
	
}
