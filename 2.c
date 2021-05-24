#include<stdio.h>

int pazar_fonksiyonu(int gun, int ay, int yil){
	
	while(1){//Sonsuz bir döngü baþlatýlýr
		gun+=7;//1.1.1900 tarihi PAZARTESÝ  olduðu dikkate alýnarak her 7 günde bir PAZARTESÝ olacaðý için, gün deðiþkeni YEDÝÞER olarak artýrýlýr 
		if(gun>30){//Gün yediþerli artarken 30 gün üzerine çýkarsa ay aþýlacaðýndan dolayý;
			gun=gun-30;//Yeni geçilen ayýn hangi günü olduðu belirlenmelidir.
			if(gun==1){//Eðer gün ayýn baþýna denk gelmiþse bugün PAZARTESÝ demektir.
				printf("%d.%d.%d\n",gun,ay,yil);}//Bu tarih bastýrýlýr
			ay++;//Ay deðiþkeni 1 artýrýlýr
			if(ay>12){//Eðer ay da 12'yi aþmýþsa yeni yýla geçilmiþ demektir
				ay=1;//Yeni yýlýn ilk ayý
				yil++;//Yýl deðiþkeni 1 artýrýlýr.
				if(yil>2000){//Eðer yýl 2000'e gelmiþse dögü kýrýlýr.
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
