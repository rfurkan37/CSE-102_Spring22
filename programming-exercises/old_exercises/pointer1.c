#include <stdio.h>
#include <string.h>


int main(){
	int sayi1=15;
	int sayi2=25;
	char kelime ='c';
	int *pointer1,*pointer2;
	pointer1=&sayi1;
	pointer2=&sayi2; 
	
	*pointer1+=1;
	
	
	
	printf("sayi1 in degeri:%d\nsayi1 in bellekteki adresi:%d\nsayi1in bellekteki hekzadecimal adresi:%x",sayi1,&sayi1,&sayi1);
	printf("\nsayi2 in degeri:%d\nsayi2 in bellekteki adresi:%d\nsayi2in bellekteki hekzadecimal adresi:%x",sayi2,&sayi2,&sayi2);
	
	return 0 ;
	
}
