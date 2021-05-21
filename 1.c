#include<stdio.h>
//NOT: DEV C++ DERLEYICISI TURKCE KARAKTERLERI DESTEKLEMEDIGI ICIN PROGRAM "ý,ü,ö" HARFLERINI ALGILAYAMAMAKTADIR.ANCAK TURKCE KARAKTER DESTEGI OLAN BIR DERLEYICIDE PROGRAM SORUNSUZ CALISACAKTIR.
char buyuk_unlu_uyumu(char dizi[10]){
	
	int i,kalin=0,ince=0;
	
	for(i=0;i<10;i++){
		
		
		if(dizi[i]=='a'|| dizi[i]=='o'|| dizi[i]=='u'|| dizi[i]=='ý'){
			printf("%c\n",dizi[i]);
	 		kalin++;}
		
		else if(dizi[i]=='e'|| dizi[i]=='i'|| dizi[i]=='ü'|| dizi[i]=='ö') {
			printf("%c\n",dizi[i]);
			ince++;}
		
		}
	
	if(kalin>0 && ince==0 ){
		printf("Buyuk Unlu Uyumuna Uygundur.");}
	
	else if(kalin==0 && ince>0 )
		{printf("Buyuk Unlu Uyumuna Uygundur.");}
	
	else 
		{printf("Buyuk Unlu Uyumuna Uygun Degildir.");}
	
}




int main(){
	
	char kelime[20];
	
	printf("Bir kelime girin:");
	scanf("%s",&kelime);
	buyuk_unlu_uyumu(kelime);
	
}
