#include<stdio.h>
//NOT: DEV C++ DERLEYICISI TURKCE KARAKTERLERI DESTEKLEMEDIGI ICIN PROGRAM "ı,ü,ö" HARFLERINI ALGILAYAMAMAKTADIR.ANCAK TURKCE KARAKTER DESTEGI OLAN BIR DERLEYICIDE PROGRAM SORUNSUZ CALISACAKTIR.
char buyuk_unlu_uyumu(char dizi[10]){
	
	int i,kalin=0,ince=0;//Kalın ve ince harfler için birer bayrak atama
	
	for(i=0;i<10;i++){//Alınan kelimenin harfleri üzerinde gezinme
		
		
		if(dizi[i]=='a'|| dizi[i]=='o'|| dizi[i]=='u'|| dizi[i]=='ı'){//Kalın harflerin tespiti
			printf("%c\n",dizi[i]);
	 		kalin++;}//Gelinen harf kalın ise kalın harf bayrağı 1 artırılır
		
		else if(dizi[i]=='e'|| dizi[i]=='i'|| dizi[i]=='ü'|| dizi[i]=='ö') {//İnce harf tespiti
			printf("%c\n",dizi[i]);
			ince++;}//Gelinen harf ince ise ince harf bayrağı 1 artırılır
		
		}
	
	if(kalin>0 && ince==0 ){//Tüm harfleri kalın harf olan bir kelime kurala uygundur
		printf("Buyuk Unlu Uyumuna Uygundur.");}
	
	else if(kalin==0 && ince>0 )//Tüm harfleri ince olan kelime de kurala uygundur
		{printf("Buyuk Unlu Uyumuna Uygundur.");}
	
	else //Bunun dışında kalan tüm kelimeler kural dışıdır
		{printf("Buyuk Unlu Uyumuna Uygun Degildir.");}
	
}




int main(){
	
	char kelime[20];
	
	printf("Bir kelime girin:");
	scanf("%s",&kelime);
	buyuk_unlu_uyumu(kelime);
	
}
