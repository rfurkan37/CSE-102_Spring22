#include <stdio.h>
#include <string.h>

int usHesaplama(int a,int b){
  int cevap=1;
  for(int i =1;i<b;i++){
  	
  	cevap*=a;
  	
  	
  	
  	
  }
printf("\nCevap budur:%d",cevap);

	
}
 
   
int main(){
	
	int sayi;
	int us;
	
	printf("Lutfen bir sayi giriniz:");
	scanf("%d",&sayi);
	printf("\nLutfen sayinin kuvvetini giriniz: ");
	scanf("%d",&us);
	
	usHesaplama(sayi,us);
	
}
