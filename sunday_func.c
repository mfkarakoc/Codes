#include<stdio.h>

int pazar_fonksiyonu(int gun, int ay, int yil){
	
	while(1){//Sonsuz bir döngü başlatılır
		gun+=7;//1.1.1900 tarihi PAZARTESİ  olduğu dikkate alınarak her 7 günde bir PAZARTESİ olacağı için, gün değişkeni YEDİŞER olarak artırılır 
		if(gun>30){//Gün yedişerli artarken 30 gün üzerine çıkarsa ay aşılacağından dolayı;
			gun=gun-30;//Yeni geçilen ayın hangi günü olduğu belirlenmelidir.
			if(gun==1){//Eğer gün ayın başına denk gelmişse bugün PAZARTESİ demektir.
				printf("%d.%d.%d\n",gun,ay,yil);}//Bu tarih bastırılır
			ay++;//Ay değişkeni 1 artırılır
			if(ay>12){//Eğer ay da 12'yi aşmışsa yeni yıla geçilmiş demektir
				ay=1;//Yeni yılın ilk ayı
				yil++;//Yıl değişkeni 1 artırılır.
				if(yil>2000){//Eğer yıl 2000'e gelmişse dögü kırılır.
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
