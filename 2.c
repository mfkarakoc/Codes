#include<stdio.h>

int pazar_fonksiyonu(int gun, int ay, int yil){
	
	while(1){//Sonsuz bir d�ng� ba�lat�l�r
		gun+=7;//1.1.1900 tarihi PAZARTES�  oldu�u dikkate al�narak her 7 g�nde bir PAZARTES� olaca�� i�in, g�n de�i�keni YED��ER olarak art�r�l�r 
		if(gun>30){//G�n yedi�erli artarken 30 g�n �zerine ��karsa ay a��laca��ndan dolay�;
			gun=gun-30;//Yeni ge�ilen ay�n hangi g�n� oldu�u belirlenmelidir.
			if(gun==1){//E�er g�n ay�n ba��na denk gelmi�se bug�n PAZARTES� demektir.
				printf("%d.%d.%d\n",gun,ay,yil);}//Bu tarih bast�r�l�r
			ay++;//Ay de�i�keni 1 art�r�l�r
			if(ay>12){//E�er ay da 12'yi a�m��sa yeni y�la ge�ilmi� demektir
				ay=1;//Yeni y�l�n ilk ay�
				yil++;//Y�l de�i�keni 1 art�r�l�r.
				if(yil>2000){//E�er y�l 2000'e gelmi�se d�g� k�r�l�r.
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
