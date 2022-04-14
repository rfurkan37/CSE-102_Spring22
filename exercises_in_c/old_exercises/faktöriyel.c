#include <stdio.h>

int num;
int fact(int);
int main(){
	
	printf("Faktoriyelini ogrenmek istediginiz sayiyi giriniz:");
	scanf("%d",&num);
	printf("faktoriyel=%d",fact(num));
	
}
int fact(int num){
	int sonuc=1;
	for(int i=1;i<=num;i++){
		sonuc*=i;
			}
		return sonuc;
}
