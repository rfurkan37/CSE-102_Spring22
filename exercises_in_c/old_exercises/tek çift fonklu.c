#include <stdio.h>

int tekcift(int a){
	
	if(a%2==0){
		
		printf("Bu sayi cifttir.");
		}
	else {
		printf("Bu sayi tektir.");
			
	}
	
	
	
}


int main(){
	
	int sayi;
	
	printf("Lutfen bir sayi giriniz:");
	scanf("%d",&sayi);
	tekcift(sayi);
	
	return 0 ;
	
	
	
	
	
	
}
