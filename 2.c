#include<stdio.h>

int pazar_fonksiyonu(int gun, int ay, int yil){
	
	while(1){
		gun+=7;
		if(gun>30){
			gun=gun-30;
			if(gun==1){
				printf("%d.%d.%d\n",gun,ay,yil);}
			ay++;
			if(ay>12){
				ay=1;
				yil++;
				if(yil>2000){
					break;}
					}
				}
		
	}
	
}



int main(){
	
	int g,a,y;
	
	printf("Gunu girin:");
	scanf("%d",&g);
	printf("Ayi girin:");
	scanf("%d",&a);
	printf("Yili girin:");
	scanf("%d",&y);
	pazar_fonksiyonu(g,a,y);
	
}
