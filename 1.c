#include<stdio.h>
//NOT: DEV C++ DERLEYICISI TURKCE KARAKTERLERI DESTEKLEMEDIGI ICIN PROGRAM "�,�,�" HARFLERINI ALGILAYAMAMAKTADIR.ANCAK TURKCE KARAKTER DESTEGI OLAN BIR DERLEYICIDE PROGRAM SORUNSUZ CALISACAKTIR.
char buyuk_unlu_uyumu(char dizi[10]){
	
	int i,kalin=0,ince=0;//Kal�n ve ince harfler i�in birer bayrak atama
	
	for(i=0;i<10;i++){//Al�nan kelimenin harfleri �zerinde gezinme
		
		
		if(dizi[i]=='a'|| dizi[i]=='o'|| dizi[i]=='u'|| dizi[i]=='�'){//Kal�n harflerin tespiti
			printf("%c\n",dizi[i]);
	 		kalin++;}//Gelinen harf kal�n ise kal�n harf bayra�� 1 art�r�l�r
		
		else if(dizi[i]=='e'|| dizi[i]=='i'|| dizi[i]=='�'|| dizi[i]=='�') {//�nce harf tespiti
			printf("%c\n",dizi[i]);
			ince++;}//Gelinen harf ince ise ince harf bayra�� 1 art�r�l�r
		
		}
	
	if(kalin>0 && ince==0 ){//T�m harfleri kal�n harf olan bir kelime kurala uygundur
		printf("Buyuk Unlu Uyumuna Uygundur.");}
	
	else if(kalin==0 && ince>0 )//T�m harfleri ince olan kelime de kurala uygundur
		{printf("Buyuk Unlu Uyumuna Uygundur.");}
	
	else //Bunun d���nda kalan t�m kelimeler kural d���d�r
		{printf("Buyuk Unlu Uyumuna Uygun Degildir.");}
	
}




int main(){
	
	char kelime[20];
	
	printf("Bir kelime girin:");
	scanf("%s",&kelime);
	buyuk_unlu_uyumu(kelime);
	
}
