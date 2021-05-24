#include<stdio.h>
//NOT: DEV C++ DERLEYICISI TURKCE KARAKTERLERI DESTEKLEMEDIGI ICIN PROGRAM "ý,ü,ö" HARFLERINI ALGILAYAMAMAKTADIR.ANCAK TURKCE KARAKTER DESTEGI OLAN BIR DERLEYICIDE PROGRAM SORUNSUZ CALISACAKTIR.
char buyuk_unlu_uyumu(char dizi[10]){
	
	int i,kalin=0,ince=0;//Kalýn ve ince harfler için birer bayrak atama
	
	for(i=0;i<10;i++){//Alýnan kelimenin harfleri üzerinde gezinme
		
		
		if(dizi[i]=='a'|| dizi[i]=='o'|| dizi[i]=='u'|| dizi[i]=='ý'){//Kalýn harflerin tespiti
			printf("%c\n",dizi[i]);
	 		kalin++;}//Gelinen harf kalýn ise kalýn harf bayraðý 1 artýrýlýr
		
		else if(dizi[i]=='e'|| dizi[i]=='i'|| dizi[i]=='ü'|| dizi[i]=='ö') {//Ýnce harf tespiti
			printf("%c\n",dizi[i]);
			ince++;}//Gelinen harf ince ise ince harf bayraðý 1 artýrýlýr
		
		}
	
	if(kalin>0 && ince==0 ){//Tüm harfleri kalýn harf olan bir kelime kurala uygundur
		printf("Buyuk Unlu Uyumuna Uygundur.");}
	
	else if(kalin==0 && ince>0 )//Tüm harfleri ince olan kelime de kurala uygundur
		{printf("Buyuk Unlu Uyumuna Uygundur.");}
	
	else //Bunun dýþýnda kalan tüm kelimeler kural dýþýdýr
		{printf("Buyuk Unlu Uyumuna Uygun Degildir.");}
	
}




int main(){
	
	char kelime[20];
	
	printf("Bir kelime girin:");
	scanf("%s",&kelime);
	buyuk_unlu_uyumu(kelime);
	
}
